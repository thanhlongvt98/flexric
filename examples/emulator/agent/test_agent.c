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

#include "../../../src/agent/e2_agent_api.h"
#include "../../../test/rnd/fill_rnd_data_gtp.h"
#include "../../../test/rnd/fill_rnd_data_mac.h"
#include "../../../test/rnd/fill_rnd_data_rlc.h"
#include "../../../test/rnd/fill_rnd_data_pdcp.h"
#include "../../../test/rnd/fill_rnd_data_slice.h"
#include "../../../test/rnd/fill_rnd_data_kpm.h"
#include "../../../test/rnd/fill_rnd_data_rc.h"

#include <assert.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <poll.h>
#include <unistd.h>

static 
gnb_e2sm_t fill_gnb_data(void)
{
  gnb_e2sm_t gnb = {0};

  // 6.2.3.16
  // Mandatory
  // AMF UE NGAP ID
  gnb.amf_ue_ngap_id = (rand() % 2^40) + 0;

  // Mandatory
  //GUAMI 6.2.3.17 
  gnb.guami.plmn_id = (e2sm_plmn_t) {.mcc = 505, .mnc = 1, .mnc_digit_len = 2};
  
  gnb.guami.amf_region_id = (rand() % 2^8) + 0;
  gnb.guami.amf_set_id = (rand() % 2^10) + 0;
  gnb.guami.amf_ptr = (rand() % 2^6) + 0;

  return gnb;
}

static 
ue_id_e2sm_t fill_ue_id_data(void)
{
  ue_id_e2sm_t ue_id_data = {0};

  ue_id_data.type = GNB_UE_ID_E2SM;
  ue_id_data.gnb = fill_gnb_data();

  return ue_id_data;
}

static 
kpm_ind_msg_format_1_t fill_kpm_ind_msg_frm_1(void)
{
  kpm_ind_msg_format_1_t msg_frm_1 = {0};

  // Measurement Data
  uint32_t num_drbs = 2;
  msg_frm_1.meas_data_lst_len = num_drbs;  // (rand() % 65535) + 1;
  msg_frm_1.meas_data_lst = calloc(msg_frm_1.meas_data_lst_len, sizeof(*msg_frm_1.meas_data_lst));
  assert(msg_frm_1.meas_data_lst != NULL && "Memory exhausted" );

  for (size_t i = 0; i < msg_frm_1.meas_data_lst_len; i++){
    // Measurement Record
    msg_frm_1.meas_data_lst[i].meas_record_len = 1;  // (rand() % 65535) + 1;
    msg_frm_1.meas_data_lst[i].meas_record_lst = calloc(msg_frm_1.meas_data_lst[i].meas_record_len, sizeof(meas_record_lst_t));
    assert(msg_frm_1.meas_data_lst[i].meas_record_lst != NULL && "Memory exhausted" );

    for (size_t j = 0; j < msg_frm_1.meas_data_lst[i].meas_record_len; j++){
      msg_frm_1.meas_data_lst[i].meas_record_lst[j].value = REAL_MEAS_VALUE; // rand()%END_MEAS_VALUE;
      msg_frm_1.meas_data_lst[i].meas_record_lst[j].real_val = (rand() % 256) + 0.1;
    }
  }

  // Measurement Information - OPTIONAL
  msg_frm_1.meas_info_lst_len = num_drbs;
  msg_frm_1.meas_info_lst = calloc(msg_frm_1.meas_info_lst_len, sizeof(meas_info_format_1_lst_t));
  assert(msg_frm_1.meas_info_lst != NULL && "Memory exhausted" );

  for (size_t i = 0; i < msg_frm_1.meas_info_lst_len; i++) {
    // Measurement Type
    msg_frm_1.meas_info_lst[i].meas_type.type = ID_MEAS_TYPE; 
    // DRB ID
    msg_frm_1.meas_info_lst[i].meas_type.id = i;

    // Label Information
    msg_frm_1.meas_info_lst[i].label_info_lst_len = 1;
    msg_frm_1.meas_info_lst[i].label_info_lst = calloc(msg_frm_1.meas_info_lst[i].label_info_lst_len, sizeof(label_info_lst_t));
    assert(msg_frm_1.meas_info_lst[i].label_info_lst != NULL && "Memory exhausted" );

    for (size_t j = 0; j < msg_frm_1.meas_info_lst[i].label_info_lst_len; j++) {
      msg_frm_1.meas_info_lst[i].label_info_lst[j].noLabel = malloc(sizeof(enum_value_e));
      *msg_frm_1.meas_info_lst[i].label_info_lst[j].noLabel = TRUE_ENUM_VALUE;
    }
  }

  return msg_frm_1;
}

static 
kpm_ind_msg_format_3_t fill_kpm_ind_msg_frm_3_sta(void)
{
  kpm_ind_msg_format_3_t msg_frm_3 = {0};

  uint32_t num_ues = 1;
  msg_frm_3.ue_meas_report_lst_len = num_ues;  // (rand() % 65535) + 1;

  msg_frm_3.meas_report_per_ue = calloc(msg_frm_3.ue_meas_report_lst_len, sizeof(meas_report_per_ue_t));
  assert(msg_frm_3.meas_report_per_ue != NULL && "Memory exhausted");

  for (size_t i = 0; i < msg_frm_3.ue_meas_report_lst_len; i++)
  {
    msg_frm_3.meas_report_per_ue[i].ue_meas_report_lst = fill_ue_id_data();
    msg_frm_3.meas_report_per_ue[i].ind_msg_format_1 = fill_kpm_ind_msg_frm_1();
  }

  return msg_frm_3;
}

static 
kpm_ric_ind_hdr_format_1_t fill_kpm_ind_hdr_frm_1(void)
{
  kpm_ric_ind_hdr_format_1_t hdr_frm_1 = {0};

  hdr_frm_1.collectStartTime = time_now_us();
  
  hdr_frm_1.fileformat_version = NULL;
  
  hdr_frm_1.sender_name = calloc(1, sizeof(byte_array_t));
  hdr_frm_1.sender_name->buf = calloc(strlen("My OAI-MONO") + 1, sizeof(char));
  memcpy(hdr_frm_1.sender_name->buf, "My OAI-MONO", strlen("My OAI-MONO"));
  hdr_frm_1.sender_name->len = strlen("My OAI-MONO");
  
  hdr_frm_1.sender_type = calloc(1, sizeof(byte_array_t));
  hdr_frm_1.sender_type->buf = calloc(strlen("MONO") + 1, sizeof(char));
  memcpy(hdr_frm_1.sender_type->buf, "MONO", strlen("MONO"));
  hdr_frm_1.sender_type->len = strlen("MONO");
  
  hdr_frm_1.vendor_name = calloc(1, sizeof(byte_array_t));
  hdr_frm_1.vendor_name->buf = calloc(strlen("OAI") + 1, sizeof(char));
  memcpy(hdr_frm_1.vendor_name->buf, "OAI", strlen("OAI"));
  hdr_frm_1.vendor_name->len = strlen("OAI");

  return hdr_frm_1;
}

static
kpm_ind_hdr_t fill_kpm_ind_hdr_sta(void)
{
  kpm_ind_hdr_t hdr = {0};

  hdr.type = FORMAT_1_INDICATION_HEADER;
  hdr.kpm_ric_ind_hdr_format_1 = fill_kpm_ind_hdr_frm_1();

  return hdr;
}

static
void read_RAN_ind(sm_ag_if_rd_ind_t* data)
{
  assert(data != NULL);
  assert(data->type == MAC_STATS_V0 || data->type == RLC_STATS_V0 ||  data->type == PDCP_STATS_V0 || data->type == SLICE_STATS_V0 || data->type == KPM_STATS_V3_0 || data->type == GTP_STATS_V0);

  if(data->type == MAC_STATS_V0){
    fill_mac_ind_data(&data->mac);
  } else if(data->type == RLC_STATS_V0){
    fill_rlc_ind_data(&data->rlc);
  } else if (data->type == PDCP_STATS_V0){
    fill_pdcp_ind_data(&data->pdcp);
  } else if(data->type == SLICE_STATS_V0){
    fill_slice_ind_data(&data->slice);
  } else if(data->type == GTP_STATS_V0){
    fill_gtp_ind_data(&data->gtp);
  } else if(data->type == KPM_STATS_V3_0){
    assert(data->kpm.act_def!= NULL && "Cannot be NULL");
    if(data->kpm.act_def->type == FORMAT_4_ACTION_DEFINITION){
     
      if(data->kpm.act_def->frm_4.matching_cond_lst[0].test_info_lst.test_cond_type == CQI_TEST_COND_TYPE
        && *data->kpm.act_def->frm_4.matching_cond_lst[0].test_info_lst.test_cond == GREATERTHAN_TEST_COND){
        printf("Matching condition: UEs with CQI greater than %ld \n", *data->kpm.act_def->frm_4.matching_cond_lst[0].test_info_lst.int_value );
      }

     printf("Parameter to report: %s \n", data->kpm.act_def->frm_4.action_def_format_1.meas_info_lst->meas_type.name.buf); 

     data->kpm.ind.hdr = fill_kpm_ind_hdr(); 
     // 7.8 Supported RIC Styles and E2SM IE Formats
     // Format 4 corresponds to indication message 3
     data->kpm.ind.msg.type = FORMAT_3_INDICATION_MESSAGE;
     data->kpm.ind.msg.frm_3 = fill_kpm_ind_msg_frm_3_sta();
    } else {
     data->kpm.ind.hdr = fill_kpm_ind_hdr(); 
     data->kpm.ind.msg = fill_kpm_ind_msg(); 
    }
  } else {
    assert("Invalid data type");
  }
}

static
void read_RAN_set(sm_ag_if_rd_e2setup_t* e2ap)
{
  assert(e2ap != NULL);

  assert(e2ap->type == KPM_V3_0_AGENT_IF_E2_SETUP_ANS_V0 || e2ap->type == RAN_CTRL_V1_3_AGENT_IF_E2_SETUP_ANS_V0);
  if(e2ap->type == KPM_V3_0_AGENT_IF_E2_SETUP_ANS_V0 ){
    e2ap->kpm.ran_func_def = fill_kpm_ran_func_def(); 
  } else if(e2ap->type == RAN_CTRL_V1_3_AGENT_IF_E2_SETUP_ANS_V0 ){
    e2ap->rc.ran_func_def = fill_rc_ran_func_def();
  } else {
    assert(0 != 0 && "Unknown type");
  }

}

static
void read_RAN(sm_ag_if_rd_t* ag_rd)
{
  assert(ag_rd->type == INDICATION_MSG_AGENT_IF_ANS_V0
      || ag_rd->type == E2_SETUP_AGENT_IF_ANS_V0);

  if(ag_rd->type == INDICATION_MSG_AGENT_IF_ANS_V0)
    return read_RAN_ind(&ag_rd->ind);
  else if(ag_rd->type == E2_SETUP_AGENT_IF_ANS_V0 )
    return read_RAN_set(&ag_rd->e2ap);
  else
    assert(0!=0 && "Unknown type");
}

static
sm_ag_if_ans_t write_RAN(sm_ag_if_wr_t const* ag_wr)
{
  assert(ag_wr!= NULL);
  assert(ag_wr->type == CONTROL_SM_AG_IF_WR);

  sm_ag_if_wr_ctrl_t const* data = &ag_wr->ctrl; 


  if(data->type == MAC_CTRL_REQ_V0){
    //printf("Control message called in the RAN \n");
    sm_ag_if_ans_t ans = {.type = CTRL_OUTCOME_SM_AG_IF_ANS_V0};
    ans.ctrl_out.type = MAC_AGENT_IF_CTRL_ANS_V0;
    ans.ctrl_out.mac.ans = MAC_CTRL_OUT_OK;
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

    sm_ag_if_ans_t ans = {.type = CTRL_OUTCOME_SM_AG_IF_ANS_V0};
    ans.ctrl_out.type = SLICE_AGENT_IF_CTRL_ANS_V0;
    return ans;

  } else if(data->type == TC_CTRL_REQ_V0){
    tc_ctrl_req_data_t const* ctrl = &data->tc_req_ctrl;

    tc_ctrl_msg_e const t = ctrl->msg.type;

    assert(t == TC_CTRL_SM_V0_CLS || t == TC_CTRL_SM_V0_PLC 
          || t == TC_CTRL_SM_V0_QUEUE || t ==TC_CTRL_SM_V0_SCH 
          || t == TC_CTRL_SM_V0_SHP || t == TC_CTRL_SM_V0_PCR);

    sm_ag_if_ans_t ans = {.type = CTRL_OUTCOME_SM_AG_IF_ANS_V0};
    ans.ctrl_out.type = TC_AGENT_IF_CTRL_ANS_V0;
    return ans;

  } else {
    assert(0 != 0 && "Not supported function ");
  }
  sm_ag_if_ans_t ans = {0};
  return ans;
}

static
void sig_handler(int sig_num)
{
  printf("\nEnding the E2 Agent with signal number = %d\n", sig_num);

  // Stop the E2 Agent
  stop_agent_api();

  exit(0);
}


int main(int argc, char *argv[])
{
  // Signal handler
  signal(SIGINT, sig_handler);

  // Init the Agent
#ifdef TEST_AGENT_GNB
  const ngran_node_t ran_type = ngran_gNB;
  const int mcc = 505;
  const int mnc = 1;
  const int mnc_digit_len = 2;
  const int nb_id = 1;
  const int cu_du_id = 0;
#elif TEST_AGENT_GNB_CU
  const ngran_node_t ran_type = ngran_gNB_CU;
  const int mcc = 505;
  const int mnc = 1;
  const int mnc_digit_len = 2;
  const int nb_id = 2;
  const int cu_du_id = 21;
#elif TEST_AGENT_GNB_DU
  const ngran_node_t ran_type = ngran_gNB_DU;
  const int mcc = 505;
  const int mnc = 1;
  const int mnc_digit_len = 2;
  const int nb_id = 2;
  const int cu_du_id = 22;
#elif TEST_AGENT_ENB
  const ngran_node_t ran_type = ngran_eNB;
  const int mcc = 208;
  const int mnc = 94;
  const int mnc_digit_len = 2;
  const int nb_id = 4;
  const int cu_du_id = 0;
#else
  static_assert( 0!=0 , "Unknown type");
#endif

  sm_io_ag_t io = {.read = read_RAN, .write = write_RAN};
  fr_args_t args = init_fr_args(argc, argv);

  if (NODE_IS_MONOLITHIC(ran_type))
    printf("[E2 AGENT]: nb_id %d, mcc %d, mnc %d, mnc_digit_len %d, ran_type %s\n", nb_id, mcc, mnc, mnc_digit_len, get_ngran_name(ran_type));
  else
    printf("[E2 AGENT]: nb_id %d, mcc %d, mnc %d, mnc_digit_len %d, ran_type %s, cu_du_id %d\n", nb_id, mcc, mnc, mnc_digit_len, get_ngran_name(ran_type), cu_du_id);
  init_agent_api(mcc, mnc, mnc_digit_len, nb_id, cu_du_id, ran_type, io, &args);

  while(1){
    poll(NULL, 0, 1000);
  }

  return EXIT_SUCCESS;
}
