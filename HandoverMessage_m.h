//
// Generated file, do not edit! Created by opp_msgc 4.2 from HandoverMessage.msg.
//

#ifndef _HANDOVERMESSAGE_M_H_
#define _HANDOVERMESSAGE_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0402
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif



/**
 * Class generated from <tt>HandoverMessage.msg</tt> by opp_msgc.
 * <pre>
 * message HandoverMessage
 * {
 *     int idMs;
 *     int idServingSrb;
 *     int idDriftSrb;
 * }
 * </pre>
 */
class HandoverMessage : public ::cMessage
{
  protected:
    int idMs_var;
    int idServingSrb_var;
    int idDriftSrb_var;

  private:
    void copy(const HandoverMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const HandoverMessage&);

  public:
    HandoverMessage(const char *name=NULL, int kind=0);
    HandoverMessage(const HandoverMessage& other);
    virtual ~HandoverMessage();
    HandoverMessage& operator=(const HandoverMessage& other);
    virtual HandoverMessage *dup() const {return new HandoverMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getIdMs() const;
    virtual void setIdMs(int idMs);
    virtual int getIdServingSrb() const;
    virtual void setIdServingSrb(int idServingSrb);
    virtual int getIdDriftSrb() const;
    virtual void setIdDriftSrb(int idDriftSrb);
};

inline void doPacking(cCommBuffer *b, HandoverMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, HandoverMessage& obj) {obj.parsimUnpack(b);}


#endif // _HANDOVERMESSAGE_M_H_