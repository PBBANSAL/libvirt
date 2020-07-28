/*
 * Implementation of  driver for Jailhouse hypervisor
 */

#include "jailhouse_driver.h"
#include "virtypedparam.h"
#include "virerror.h"
#include "virstring.h"
#include "viralloc.h"
#include "domain_conf.h"
#include "virfile.h"
#include "datatypes.h"
#include "vircommand.h"
#include <string.h>

#define UNUSED(x) (void)(x)

static virDrvOpenStatus
jailhouseConnectOpen (virConnectPtr conn, virConnectAuthPtr auth,
                      virConfPtr conf,
                      unsigned int flags)
{
    UNUSED (conn);
    UNUSED (auth);
    UNUSED (conf);
    UNUSED (flags);
    return 0;
}

static int
jailhouseConnectclose (virConnectPtr conn)
{
    UNUSED (conn);
    return 0;
}

static const char *
jailhouseConnectGetType (virConnectPtr conn)
{
    UNUSED (conn);
    return NULL;

}

static char *
jailhouseConnectGetHostname (virConnectPtr conn)
{
    UNUSED (conn);
    return NULL;
}

static int
jailhousenodeGetInfo (virConnectPtr conn, virNodeInfoPtr info)
{
    UNUSED (conn);
    UNUSED (info);
    return -1;
}

static int
jailhouseConnectListDomains (virConnectPtr conn, int *ids, int maxids)
{
    UNUSED (conn);
    UNUSED (ids);
    UNUSED (maxids);
    return -1;
}

static int
jailhouseConnectNumOfDomains (virConnectPtr conn)
{
    UNUSED (conn);
    return -1;
}

static int
jailhouseConnectListAllDomains (virConnectPtr conn, virDomainPtr **domain,
                                unsigned int flags)
{
    UNUSED (conn);
    UNUSED (domain);
    UNUSED (flags);
    return -1;
}

static virDomainPtr
jailhouseDomainLookupByID (virConnectPtr conn, int id)
{
    UNUSED (conn);
    UNUSED (id);
    return NULL;
}

static virDomainPtr
jailhouseDomainLookupByName (virConnectPtr conn, const char *name)
{
    UNUSED (conn);
    UNUSED (name);
    return NULL;
}

static virDomainPtr
jailhouseDomainLookupByUUID (virConnectPtr conn, const unsigned char *uuid)
{
    UNUSED (conn);
    UNUSED (uuid);
    return NULL;
}

static int
jailhouseDomainCreate (virDomainPtr domain)
{
    UNUSED (domain);
    return -1;

}

static int
jailhouseDomainShutdown (virDomainPtr domain)
{
    UNUSED (domain);
    return -1;
}


static int
jailhouseDomainDestroy (virDomainPtr domain)
{
    UNUSED (domain);
    return -1;
}

static int
jailhouseDomainGetInfo (virDomainPtr domain, virDomainInfoPtr info)
{
    UNUSED (domain);
    UNUSED (info);
    return -1;
}

static int
jailhouseDomainGetState (virDomainPtr domain, int *state, int *reason,
                         unsigned int flags)
{
    UNUSED (domain);
    UNUSED (state);
    UNUSED (reason);
    UNUSED (flags);
    return -1;
}

static char *
jailhouseGetXMLDesc (virDomainPtr domain, unsigned int flags)
{
    UNUSED (domain);
    UNUSED (flags);
    return NULL;
}

static virHypervisorDriver jailhouseHypervisorDriver = {
    .name = "JAILHOUSE",
    .connectOpen = jailhouseConnectOpen,
    .connectClose = jailhouseConnectclose,
    .connectListDomains = jailhouseConnectListDomains,
    .connectNumOfDomains = jailhouseConnectNumOfDomains,
    .connectListAllDomains = jailhouseConnectListAllDomains,
    .domainLookupByID = jailhouseDomainLookupByID,
    .domainLookupByUUID = jailhouseDomainLookupByUUID,
    .domainLookupByName = jailhouseDomainLookupByName,
    .domainGetXMLDesc = jailhouseGetXMLDesc,
    .domainCreate = jailhouseDomainCreate,
    .connectGetType = jailhouseConnectGetType,
    .connectGetHostname = jailhouseConnectGetHostname,
    .nodeGetInfo = jailhousenodeGetInfo,
    .domainShutdown = jailhouseDomainShutdown,
    .domainDestroy = jailhouseDomainDestroy,
    .domainGetInfo = jailhouseDomainGetInfo,
    .domainGetState = jailhouseDomainGetState,
};

static virConnectDriver jailhouseConnectDriver = {
    .hypervisorDriver = &jailhouseHypervisorDriver,
};

int
jailhouseRegister (void)
{
    return virRegisterConnectDriver (&jailhouseConnectDriver, false);
}
