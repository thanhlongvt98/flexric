/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

#include "../../src/agent/e2_agent_api.h"
#include "../../src/ric/near_ric_api.h"
#include "../../src/xApp/e42_xapp_api.h"
#include "../../src/sm/slice_sm/slice_sm_id.h"
#include "../../src/sm/gtp_sm/gtp_sm_id.h"
#include "../../src/sm/kpm_sm_v2.02/kpm_sm_id.h"
#include "../../src/util/alg_ds/alg/defer.h"
#include "../../src/util/time_now_us.h"
#include "../sm/common/fill_ind_data.h"
#include "../sm/kpm_sm/fill_kpm_ind_data/fill_kpm_ind_data.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

static
void read_RAN(sm_ag_if_rd_t* data)
{
  assert(data->type == MAC_STATS_V0 || 
        data->type == RLC_STATS_V0 ||  
        data->type == PDCP_STATS_V0 || 
        data->type == SLICE_STATS_V0 || 
        data->type == KPM_STATS_V0 ||
        data->type == GTP_STATS_V0);

  if(data->type == MAC_STATS_V0 ){
    fill_mac_ind_data(&data->mac_stats);
  } else if(data->type == RLC_STATS_V0) {
    fill_rlc_ind_data(&data->rlc_stats);
  } else if (data->type == PDCP_STATS_V0 ){
    fill_pdcp_ind_data(&data->pdcp_stats);
  } else if(data->type == SLICE_STATS_V0 ){
    fill_slice_ind_data(&data->slice_stats);
  } else if(data->type == GTP_STATS_V0 ){
    fill_gtp_ind_data(&data->gtp_stats);
  } else if(data->type == KPM_STATS_V0 ){
    fill_kpm_ind_data(&data->kpm_stats);
  } else {
    assert("Invalid data type");
  }
}

static
sm_ag_if_ans_t write_RAN(sm_ag_if_wr_t const* data)
{
  assert(data != NULL);
  if(data->type == MAC_CTRL_REQ_V0){
    //printf("Control message called in the RAN \n");
    sm_ag_if_ans_t ans = {.type = MAC_AGENT_IF_CTRL_ANS_V0};
    ans.mac.ans = MAC_CTRL_OUT_OK;
    return ans;
  } else if(data->type == SLICE_CTRL_REQ_V0 ){

    slice_ctrl_req_data_t const* slice_req_ctrl = &data->slice_req_ctrl;
    slice_ctrl_msg_t const* msg = &slice_req_ctrl->msg;

    if(msg->type == SLICE_CTRL_SM_V0_ADD){
        printf("[E2 Agent]: SLICE CONTROL ADD rx\n");
    } else if (msg->type == SLICE_CTRL_SM_V0_DEL){
        printf("[E2 Agent]: SLICE CONTROL DEL rx\n");
    } else if (msg->type == SLICE_CTRL_SM_V0_UE_SLICE_ASSOC){
        printf("[E2 Agent]: SLICE CONTROL ASSOC rx\n");
    } else {
      assert(0!=0 && "Unknown msg_type!");
    }

    sm_ag_if_ans_t ans = {.type =  SLICE_AGENT_IF_CTRL_ANS_V0};
    return ans;
  } else {
    assert(0 != 0 && "Not supported function ");
  }
  sm_ag_if_ans_t ans = {0};
  return ans;
}

static void sm_cb_kpm_ind_msg_frm_1(const kpm_ind_msg_format_1_t * msg)
{
  assert(msg != NULL);

  // TO DO BETTER

  for (size_t i = 0; i < msg->meas_info_lst_len; ++i) {
    meas_info_format_1_lst_t* mi = &msg->meas_info_lst[i];
    assert(mi->meas_type.type == NAME_MEAS_TYPE);
    printf("%s ", (char *)(mi->meas_type.name.buf));

    assert(msg->meas_data_lst[i].meas_record_len == 1);
    const meas_record_lst_t* mdi = &msg->meas_data_lst[i].meas_record_lst[0];
    if (mdi->value == INTEGER_MEAS_VALUE)
      printf(" %7d ", mdi->int_val);
    else
      printf(" %7.3f ", mdi->real_val);

    assert(mi->label_info_lst_len == 1);
    if (mi->label_info_lst[0].plmn_id != NULL) {
      const plmn_t* plmn = mi->label_info_lst[0].plmn_id;
      printf(" (PLMN %03d.%0*d)",
             plmn->mcc, plmn->mnc_digit_len, plmn->mnc);
    }
    printf("\n");
  }

}

static
void sm_cb_kpm(sm_ag_if_rd_t const* rd)
{
  assert(rd != NULL);
  assert(rd->type == KPM_STATS_V0); 

  // kpm_ric_indication_t * read_kpm_ind = calloc(1, sizeof(kpm_ric_indication_t));
  // read_kpm_ind = &rd->kpm_stats;

  kpm_ric_indication_t read_kpm_ind = rd->kpm_stats;
  // Indication Header
  
  switch (read_kpm_ind.kpm_ind_hdr.type)
  {
  case FORMAT_1_INDICATION_HEADER:
    printf("received KPM indication at %d (sender '%s', type '%s', vendor '%s')\n",
         read_kpm_ind.kpm_ind_hdr.kpm_ric_ind_hdr_format_1.collectStartTime, (char *)(read_kpm_ind.kpm_ind_hdr.kpm_ric_ind_hdr_format_1.sender_name->buf), (char *)(read_kpm_ind.kpm_ind_hdr.kpm_ric_ind_hdr_format_1.sender_type->buf), (char *)(read_kpm_ind.kpm_ind_hdr.kpm_ric_ind_hdr_format_1.vendor_name->buf));
    break;
  
  default:
    assert(false && "Unknown Indication Header Type");
  }

  // Indication Message
  
  switch (read_kpm_ind.kpm_ind_msg.type)
  {
  case FORMAT_1_INDICATION_MESSAGE:
    sm_cb_kpm_ind_msg_frm_1(&read_kpm_ind.kpm_ind_msg.frm_1);
    break;
  
  // case FORMAT_2_INDICATION_MESSAGE:
  //   sm_cb_kpm_ind_msg_frm_2(&read_kpm_ind->kpm_ind_msg.frm_2);
  //   break;

  // case FORMAT_3_INDICATION_MESSAGE:
  //   sm_cb_kpm_ind_msg_frm_3(&read_kpm_ind->kpm_ind_msg.frm_3);
  //   break;

  default:
    assert(false && "Unknown Indication Message Type");
  }
}

int main(int argc, char *argv[])
{
  // Init the Agent
  const int mcc = 208; 
  const int mnc = 92; 
  const int mnc_digit_len = 2;
  const int nb_id = 42;
  const int cu_du_id = 0;
  ngran_node_t ran_type = ngran_gNB;
  sm_io_ag_t io = {.read = read_RAN, .write = write_RAN};

  fr_args_t args = init_fr_args(argc, argv);  // Parse arguments
  
  init_agent_api( mcc, mnc, mnc_digit_len, nb_id, cu_du_id, ran_type, io, &args);
  sleep(1);

  // Init the RIC
  init_near_ric_api(&args);
  sleep(2);

  //Init the xApp
  init_xapp_api(&args);
  sleep(1);

  e2_node_arr_t nodes = e2_nodes_xapp_api();
  defer({ free_e2_node_arr(&nodes); });

  assert(nodes.len > 0);

  printf("Connected E2 nodes = %d\n", nodes.len );

  e2_node_connected_t* n = &nodes.n[0];
  for(size_t i = 0; i < n->len_rf; ++i)
    printf("Registered ran func id = %d \n ", n->ack_rf[i].id );

  inter_xapp_e i = ms_1000;
  // returns a handle for KPM
  sm_ans_xapp_t h = report_sm_xapp_api(&nodes.n[0].id, SM_KPM_ID, i, sm_cb_kpm);
  assert(h.success == true);
  sleep(20);

  // Remove the handle previously returned
  rm_report_sm_xapp_api(h.u.handle);

  sleep(1);

  // Stop the Agent
  stop_agent_api();

  // Stop the RIC
  stop_near_ric_api();

  //Stop the xApp
  while(try_stop_xapp_api() == false)
    usleep(1000);     

  printf("Test communicating E2-Agent, Near-RIC and xApp run SUCCESSFULLY\n");
}

