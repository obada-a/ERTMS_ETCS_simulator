#
# OMNeT++/OMNEST Makefile for Treno2
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out
#

# Name of target to be created (-o option)
TARGET = Treno2$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I. \
    -IBSC \
    -IChannels \
    -IChannels/CanaleDati \
    -IChannels/CanalePilota \
    -IChannels/CanaleSegnalazione \
    -IMobileStation \
    -IMobilityManager \
    -ISRB \
    -ITopologyManager \
    -ITreno

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/BSC/Tx_BSC.o \
    $O/BSC/AddressRegister.o \
    $O/BSC/DecisoreHandover.o \
    $O/BSC/DataManagerBsc.o \
    $O/BSC/Register.o \
    $O/BSC/Component.o \
    $O/BSC/Rx_BSC.o \
    $O/BSC/AccessManager.o \
    $O/Channels/Rx_from_MS.o \
    $O/Channels/Rx_from_SRB.o \
    $O/Channels/DistanceRx.o \
    $O/Channels/CanaleDati/RxDati_from_MS.o \
    $O/Channels/CanaleDati/FiltroMessaggiDati.o \
    $O/Channels/CanaleDati/TxDati_to_SRB.o \
    $O/Channels/CanaleDati/RxDati_from_SRB.o \
    $O/Channels/CanaleDati/TxDati_to_MS.o \
    $O/Channels/CanalePilota/RxPilota_from_MS.o \
    $O/Channels/CanalePilota/RxPilota_from_SRB.o \
    $O/Channels/CanalePilota/TxPilota_to_SRB.o \
    $O/Channels/CanalePilota/FiltroMessaggiPilota.o \
    $O/Channels/CanalePilota/TxPilota_to_MS.o \
    $O/Channels/CanaleSegnalazione/RxSegnalazione_from_SRB.o \
    $O/Channels/CanaleSegnalazione/FiltroMessaggiSegnalazione.o \
    $O/Channels/CanaleSegnalazione/RxSegnalazione_from_MS.o \
    $O/Channels/CanaleSegnalazione/TxSegnalazione_to_SRB.o \
    $O/Channels/CanaleSegnalazione/TxSegnalazione_to_MS.o \
    $O/MobileStation/SrbPower.o \
    $O/MobileStation/NetworkAccessManager.o \
    $O/MobileStation/Tx_MS.o \
    $O/MobileStation/PowerManager.o \
    $O/MobileStation/HandoverManager.o \
    $O/MobileStation/DataManagerMs.o \
    $O/MobileStation/Rx_MS.o \
    $O/MobilityManager/MobilityManager.o \
    $O/SRB/HelloManager.o \
    $O/SRB/Rx_from_Channel.o \
    $O/SRB/Tx_to_Channel.o \
    $O/SRB/Rx_from_BSC.o \
    $O/SRB/Tx_to_BSC.o \
    $O/TopologyManager/Punto.o \
    $O/TopologyManager/TopologyManager.o \
    $O/DriftSrbConfiguration_m.o \
    $O/PositionUpdateMessage_m.o \
    $O/PowerMessage_m.o \
    $O/PresenceMessage_m.o \
    $O/ConnectionConfiguration_m.o \
    $O/NetworkAccessRequestMessage_m.o \
    $O/HelloMessage_m.o \
    $O/BestSrbRespons_m.o \
    $O/DistanceMessage_m.o \
    $O/HandoverUpdate_m.o \
    $O/RegistrationMessage_m.o \
    $O/HandoverMessage_m.o \
    $O/NetworkAccessConfirmationMessage_m.o

# Message files
MSGFILES = \
    DriftSrbConfiguration.msg \
    PositionUpdateMessage.msg \
    PowerMessage.msg \
    PresenceMessage.msg \
    ConnectionConfiguration.msg \
    NetworkAccessRequestMessage.msg \
    HelloMessage.msg \
    BestSrbRespons.msg \
    DistanceMessage.msg \
    HandoverUpdate.msg \
    RegistrationMessage.msg \
    HandoverMessage.msg \
    NetworkAccessConfirmationMessage.msg

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(CXX) -c $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	-rm -rf $O
	-rm -f Treno2 Treno2.exe libTreno2.so libTreno2.a libTreno2.dll libTreno2.dylib
	-rm -f ./*_m.cc ./*_m.h
	-rm -f BSC/*_m.cc BSC/*_m.h
	-rm -f Channels/*_m.cc Channels/*_m.h
	-rm -f Channels/CanaleDati/*_m.cc Channels/CanaleDati/*_m.h
	-rm -f Channels/CanalePilota/*_m.cc Channels/CanalePilota/*_m.h
	-rm -f Channels/CanaleSegnalazione/*_m.cc Channels/CanaleSegnalazione/*_m.h
	-rm -f MobileStation/*_m.cc MobileStation/*_m.h
	-rm -f MobilityManager/*_m.cc MobilityManager/*_m.h
	-rm -f SRB/*_m.cc SRB/*_m.h
	-rm -f TopologyManager/*_m.cc TopologyManager/*_m.h
	-rm -f Treno/*_m.cc Treno/*_m.h

cleanall: clean
	-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc BSC/*.cc Channels/*.cc Channels/CanaleDati/*.cc Channels/CanalePilota/*.cc Channels/CanaleSegnalazione/*.cc MobileStation/*.cc MobilityManager/*.cc SRB/*.cc TopologyManager/*.cc Treno/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/BestSrbRespons_m.o: BestSrbRespons_m.cc \
	BestSrbRespons_m.h
$O/ConnectionConfiguration_m.o: ConnectionConfiguration_m.cc \
	ConnectionConfiguration_m.h
$O/DistanceMessage_m.o: DistanceMessage_m.cc \
	DistanceMessage_m.h
$O/DriftSrbConfiguration_m.o: DriftSrbConfiguration_m.cc \
	DriftSrbConfiguration_m.h
$O/HandoverMessage_m.o: HandoverMessage_m.cc \
	HandoverMessage_m.h
$O/HandoverUpdate_m.o: HandoverUpdate_m.cc \
	HandoverUpdate_m.h
$O/HelloMessage_m.o: HelloMessage_m.cc \
	HelloMessage_m.h
$O/NetworkAccessConfirmationMessage_m.o: NetworkAccessConfirmationMessage_m.cc \
	NetworkAccessConfirmationMessage_m.h
$O/NetworkAccessRequestMessage_m.o: NetworkAccessRequestMessage_m.cc \
	NetworkAccessRequestMessage_m.h
$O/PositionUpdateMessage_m.o: PositionUpdateMessage_m.cc \
	PositionUpdateMessage_m.h
$O/PowerMessage_m.o: PowerMessage_m.cc \
	PowerMessage_m.h
$O/PresenceMessage_m.o: PresenceMessage_m.cc \
	PresenceMessage_m.h
$O/RegistrationMessage_m.o: RegistrationMessage_m.cc \
	RegistrationMessage_m.h
$O/BSC/AccessManager.o: BSC/AccessManager.cc \
	NetworkAccessConfirmationMessage_m.h \
	NetworkAccessRequestMessage_m.h \
	RegistrationMessage_m.h
$O/BSC/AddressRegister.o: BSC/AddressRegister.cc \
	BSC/Component.h \
	BSC/Register.h \
	HandoverUpdate_m.h \
	PresenceMessage_m.h \
	RegistrationMessage_m.h
$O/BSC/Component.o: BSC/Component.cc \
	BSC/Component.h
$O/BSC/DataManagerBsc.o: BSC/DataManagerBsc.cc
$O/BSC/DecisoreHandover.o: BSC/DecisoreHandover.cc \
	HandoverMessage_m.h \
	HandoverUpdate_m.h \
	MobileStation/SrbPower.h \
	PowerMessage_m.h \
	PresenceMessage_m.h
$O/BSC/Register.o: BSC/Register.cc \
	BSC/Component.h \
	BSC/Register.h
$O/BSC/Rx_BSC.o: BSC/Rx_BSC.cc
$O/BSC/Tx_BSC.o: BSC/Tx_BSC.cc \
	HandoverMessage_m.h \
	NetworkAccessConfirmationMessage_m.h
$O/Channels/DistanceRx.o: Channels/DistanceRx.cc \
	DistanceMessage_m.h
$O/Channels/Rx_from_MS.o: Channels/Rx_from_MS.cc
$O/Channels/Rx_from_SRB.o: Channels/Rx_from_SRB.cc
$O/Channels/CanaleDati/FiltroMessaggiDati.o: Channels/CanaleDati/FiltroMessaggiDati.cc \
	DistanceMessage_m.h
$O/Channels/CanaleDati/RxDati_from_MS.o: Channels/CanaleDati/RxDati_from_MS.cc
$O/Channels/CanaleDati/RxDati_from_SRB.o: Channels/CanaleDati/RxDati_from_SRB.cc
$O/Channels/CanaleDati/TxDati_to_MS.o: Channels/CanaleDati/TxDati_to_MS.cc
$O/Channels/CanaleDati/TxDati_to_SRB.o: Channels/CanaleDati/TxDati_to_SRB.cc
$O/Channels/CanalePilota/FiltroMessaggiPilota.o: Channels/CanalePilota/FiltroMessaggiPilota.cc \
	DistanceMessage_m.h \
	HelloMessage_m.h
$O/Channels/CanalePilota/RxPilota_from_MS.o: Channels/CanalePilota/RxPilota_from_MS.cc
$O/Channels/CanalePilota/RxPilota_from_SRB.o: Channels/CanalePilota/RxPilota_from_SRB.cc
$O/Channels/CanalePilota/TxPilota_to_MS.o: Channels/CanalePilota/TxPilota_to_MS.cc
$O/Channels/CanalePilota/TxPilota_to_SRB.o: Channels/CanalePilota/TxPilota_to_SRB.cc
$O/Channels/CanaleSegnalazione/FiltroMessaggiSegnalazione.o: Channels/CanaleSegnalazione/FiltroMessaggiSegnalazione.cc \
	DistanceMessage_m.h \
	HandoverMessage_m.h \
	NetworkAccessConfirmationMessage_m.h \
	NetworkAccessRequestMessage_m.h \
	PowerMessage_m.h
$O/Channels/CanaleSegnalazione/RxSegnalazione_from_MS.o: Channels/CanaleSegnalazione/RxSegnalazione_from_MS.cc
$O/Channels/CanaleSegnalazione/RxSegnalazione_from_SRB.o: Channels/CanaleSegnalazione/RxSegnalazione_from_SRB.cc
$O/Channels/CanaleSegnalazione/TxSegnalazione_to_MS.o: Channels/CanaleSegnalazione/TxSegnalazione_to_MS.cc
$O/Channels/CanaleSegnalazione/TxSegnalazione_to_SRB.o: Channels/CanaleSegnalazione/TxSegnalazione_to_SRB.cc \
	NetworkAccessRequestMessage_m.h \
	PowerMessage_m.h
$O/MobileStation/DataManagerMs.o: MobileStation/DataManagerMs.cc
$O/MobileStation/HandoverManager.o: MobileStation/HandoverManager.cc \
	DriftSrbConfiguration_m.h \
	HandoverMessage_m.h
$O/MobileStation/NetworkAccessManager.o: MobileStation/NetworkAccessManager.cc \
	BestSrbRespons_m.h \
	ConnectionConfiguration_m.h \
	NetworkAccessRequestMessage_m.h
$O/MobileStation/PowerManager.o: MobileStation/PowerManager.cc \
	BestSrbRespons_m.h \
	DistanceMessage_m.h \
	HelloMessage_m.h \
	MobileStation/SrbPower.h \
	PowerMessage_m.h
$O/MobileStation/Rx_MS.o: MobileStation/Rx_MS.cc \
	ConnectionConfiguration_m.h \
	DriftSrbConfiguration_m.h \
	HelloMessage_m.h
$O/MobileStation/SrbPower.o: MobileStation/SrbPower.cc \
	MobileStation/SrbPower.h
$O/MobileStation/Tx_MS.o: MobileStation/Tx_MS.cc \
	ConnectionConfiguration_m.h \
	DriftSrbConfiguration_m.h \
	PowerMessage_m.h
$O/MobilityManager/MobilityManager.o: MobilityManager/MobilityManager.cc \
	PositionUpdateMessage_m.h
$O/SRB/HelloManager.o: SRB/HelloManager.cc \
	HelloMessage_m.h
$O/SRB/Rx_from_BSC.o: SRB/Rx_from_BSC.cc
$O/SRB/Rx_from_Channel.o: SRB/Rx_from_Channel.cc
$O/SRB/Tx_to_BSC.o: SRB/Tx_to_BSC.cc
$O/SRB/Tx_to_Channel.o: SRB/Tx_to_Channel.cc
$O/TopologyManager/Punto.o: TopologyManager/Punto.cc \
	TopologyManager/Punto.h
$O/TopologyManager/TopologyManager.o: TopologyManager/TopologyManager.cc \
	DistanceMessage_m.h \
	TopologyManager/Punto.h

