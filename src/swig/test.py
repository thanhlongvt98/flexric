import flexric as ric
import time
import pdb


def create_static_slice(idx, low, high):
    s = ric.slice_t()

    s.id = idx

    s.len_label = 0
    s.label = None

    s.len_sched = 0
    s.sched = None

    s.params.type = ric.SLICE_ALG_SM_V0_STATIC 
    s.params.u.sta.pos_high = high
    s.params.u.sta.pos_low = low
    #pdb.set_trace()
    return s



####################
#### MAC INDICATION CALLBACK
####################

#  MACCallback class is defined and derived from C++ class mac_cb
class MACCallback(ric.mac_cb):
# Define Python class 'constructor'
    def __init__(self):
        # Call C++ base class constructor
        ric.mac_cb.__init__(self)
    # Override C++ method: virtual void handle(swig_mac_ind_msg_t a) = 0;
    def handle(self, ind):
    # Print swig_mac_ind_msg_t 
        if len(ind.ue_stats) > 0:
            t_now = time.time_ns() / 1000.0
            t_mac = ind.tstamp / 1.0
            t_diff = t_now - t_mac
            print('MAC Indication tstamp = ' + str(t_mac) + ' diff = ' + str(t_diff))
            print('MAC rnti = ' + str(ind.ue_stats[0].rnti))

####################
#### RLC INDICATION CALLBACK
####################

class RLCCallback(ric.rlc_cb):
# Define Python class 'constructor'
    def __init__(self):
        # Call C++ base class constructor
        ric.rlc_cb.__init__(self)
    # Override C++ method: virtual void handle(swig_rlc_ind_msg_t a) = 0;
    def handle(self, ind):
    # Print swig_rlc_ind_msg_t 
        if len(ind.rb_stats) > 0:
            print('RLC Indication tstamp = ' + str(ind.tstamp))
            print('RLC rnti = '+ str(ind.rb_stats[0].rnti))

####################
#### PDCP INDICATION CALLBACK
####################

class PDCPCallback(ric.pdcp_cb):
# Define Python class 'constructor'
    def __init__(self):
        # Call C++ base class constructor
        ric.pdcp_cb.__init__(self)
    # Override C++ method: virtual void handle(swig_pdcp_ind_msg_t a) = 0;
    def handle(self, ind):
    # Print swig_pdcp_ind_msg_t 
        if len(ind.rb_stats) > 0:
            print('PDCP Indication tstamp = ' + str(ind.tstamp))
            print('PDCP rnti = '+ str(ind.rb_stats[0].rnti))


####################
####  GENERAL 
####################

ric.init("127.0.0.1")

conn = ric.conn_e2_nodes()
assert(len(conn) > 0)
print("Global E2 Node [0]: PLMN MCC = " + str(conn[0].id.plmn.mcc) )
print("Global E2 Node [0]: PLMN MNC = " + str(conn[0].id.plmn.mnc) )

#print("Global E2 Node [1]: PLMN MCC = " + str(conn[1].id.plmn.mcc) )
#print("Global E2 Node [1]: PLMN MNC = " + str(conn[1].id.plmn.mnc) )

####################
#### MAC INDICATION
####################

mac_cb = MACCallback()
ric.report_mac_sm(conn[0].id, ric.Interval_ms_1, mac_cb)

time.sleep(5)

####################
#### RLC INDICATION
####################

rlc_cb = RLCCallback()
ric.report_rlc_sm(conn[0].id, ric.Interval_ms_1, rlc_cb)

####################
#### PDCP INDICATION
####################

#pdcp_cb = PDCPCallback()
#ric.report_pdcp_sm(conn[0].id, ric.Interval_ms_1, pdcp_cb)




####################
####  SLICE CTRL ASSOC
####################

msg = ric.slice_ctrl_msg_t()
msg.type = ric.SLICE_CTRL_SM_V0_UE_SLICE_ASSOC
msg.u.ue_slice.len_ue_slice = 2
assoc = ric.ue_slice_assoc_array(2)

one = ric.ue_slice_assoc_t()
one.dl_id = 0
one.ul_id = 0
one.rnti = 42
assoc[0] = one

two = ric.ue_slice_assoc_t()
two.dl_id = 0
two.ul_id = 0
two.rnti = 43
assoc[1] = two

msg.u.ue_slice.ues = assoc 

ric.control_slice_sm(conn[0].id, msg)
print('Sent control slice')
time.sleep(2)

####################
####  SLICE CTRL ADD
####################

msg = ric.slice_ctrl_msg_t()
msg.type = ric.SLICE_CTRL_SM_V0_ADD

dl = ric.ul_dl_slice_conf_t()
#ul = ric.ul_dl_slice_conf_t()

dl.len_sched_name = 0
dl.sched_name = None


dl.len_slices = 2

slices = ric.slice_array(2)

idx = 0
low = 0
high = 5
slices[0] = create_static_slice(idx, low, high)
slices[1] = create_static_slice(idx+1, low+6, high+6)


dl.slices = slices

msg.u.add_mod_slice.dl = dl; 
#msg.u.add_mod_slice.ul = ul; 

ric.control_slice_sm(conn[0].id, msg)


time.sleep(2)

ric.rm_report_mac_sm()

ric.rm_report_rlc_sm()

# Avoid deadlock. ToDo revise architecture 
while ric.try_stop == 0:
    time.sleep(1)

print('Test finished' )

