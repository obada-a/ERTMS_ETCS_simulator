//
// Generated file, do not edit! Created by opp_msgc 4.2 from DriftSrbConfiguration.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "DriftSrbConfiguration_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(DriftSrbConfiguration);

DriftSrbConfiguration::DriftSrbConfiguration(const char *name, int kind) : cMessage(name,kind)
{
    this->idDriftSrb_var = 0;
}

DriftSrbConfiguration::DriftSrbConfiguration(const DriftSrbConfiguration& other) : cMessage(other)
{
    copy(other);
}

DriftSrbConfiguration::~DriftSrbConfiguration()
{
}

DriftSrbConfiguration& DriftSrbConfiguration::operator=(const DriftSrbConfiguration& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void DriftSrbConfiguration::copy(const DriftSrbConfiguration& other)
{
    this->idDriftSrb_var = other.idDriftSrb_var;
}

void DriftSrbConfiguration::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->idDriftSrb_var);
}

void DriftSrbConfiguration::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->idDriftSrb_var);
}

int DriftSrbConfiguration::getIdDriftSrb() const
{
    return idDriftSrb_var;
}

void DriftSrbConfiguration::setIdDriftSrb(int idDriftSrb)
{
    this->idDriftSrb_var = idDriftSrb;
}

class DriftSrbConfigurationDescriptor : public cClassDescriptor
{
  public:
    DriftSrbConfigurationDescriptor();
    virtual ~DriftSrbConfigurationDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(DriftSrbConfigurationDescriptor);

DriftSrbConfigurationDescriptor::DriftSrbConfigurationDescriptor() : cClassDescriptor("DriftSrbConfiguration", "cMessage")
{
}

DriftSrbConfigurationDescriptor::~DriftSrbConfigurationDescriptor()
{
}

bool DriftSrbConfigurationDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DriftSrbConfiguration *>(obj)!=NULL;
}

const char *DriftSrbConfigurationDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DriftSrbConfigurationDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int DriftSrbConfigurationDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *DriftSrbConfigurationDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "idDriftSrb",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int DriftSrbConfigurationDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "idDriftSrb")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DriftSrbConfigurationDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *DriftSrbConfigurationDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int DriftSrbConfigurationDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DriftSrbConfiguration *pp = (DriftSrbConfiguration *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DriftSrbConfigurationDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DriftSrbConfiguration *pp = (DriftSrbConfiguration *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getIdDriftSrb());
        default: return "";
    }
}

bool DriftSrbConfigurationDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DriftSrbConfiguration *pp = (DriftSrbConfiguration *)object; (void)pp;
    switch (field) {
        case 0: pp->setIdDriftSrb(string2long(value)); return true;
        default: return false;
    }
}

const char *DriftSrbConfigurationDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *DriftSrbConfigurationDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DriftSrbConfiguration *pp = (DriftSrbConfiguration *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


