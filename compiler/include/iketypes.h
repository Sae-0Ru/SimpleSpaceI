/*** Autogenerated by WIDL 8.12 from include/iketypes.idl - Do not edit ***/

#ifdef _WIN32
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif
#include <rpc.h>
#include <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __iketypes_h__
#define __iketypes_h__

#ifndef __WIDL_INLINE
#if defined(__cplusplus) || defined(_MSC_VER)
#define __WIDL_INLINE inline
#elif defined(__GNUC__)
#define __WIDL_INLINE __inline__
#endif
#endif

/* Forward declarations */

/* Headers for imported files */

#include <fwptypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#include <winapifamily.h>
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#define IKEEXT_ERROR_CODE_COUNT (ERROR_IPSEC_IKE_NEG_STATUS_END - ERROR_IPSEC_IKE_NEG_STATUS_BEGIN)

/* Please keep in sync with winerror.h defines.  */

#define IKEEXT_CERT_FLAG_ENABLE_ACCOUNT_MAPPING          (0x1)
#define IKEEXT_CERT_FLAG_DISABLE_REQUEST_PAYLOAD         (0x2)
#define IKEEXT_CERT_FLAG_USE_NAP_CERTIFICATE             (0x4)
#define IKEEXT_CERT_FLAG_INTERMEDIATE_CA                 (0x8)
#define IKEEXT_CERT_FLAG_IGNORE_INIT_CERT_MAP_FAILURE    (0x10)
#define IKEEXT_CERT_FLAG_PREFER_NAP_CERTIFICATE_OUTBOUND (0x20)
#if (NTDDI_VERSION >= NTDDI_WIN8)
#define IKEEXT_CERT_FLAG_SELECT_NAP_CERTIFICATE          (0x40)
#define IKEEXT_CERT_FLAG_VERIFY_NAP_CERTIFICATE          (0x80)
#define IKEEXT_CERT_FLAG_FOLLOW_RENEWAL_CERTIFICATE      (0x100)
#endif

#define IKEEXT_CERT_AUTH_FLAG_SSL_ONE_WAY            (0x1)
#define IKEEXT_CERT_AUTH_FLAG_DISABLE_CRL_CHECK      (0x2)
#define IKEEXT_CERT_AUTH_ENABLE_CRL_CHECK_STRONG     (0x4)
#define IKEEXT_CERT_AUTH_DISABLE_SSL_CERT_VALIDATION (0x8)
#if (NTDDI_VERSION >= NTDDI_WIN7)
#define IKEEXT_CERT_AUTH_ALLOW_HTTP_CERT_LOOKUP      (0x10)
#define IKEEXT_CERT_AUTH_URL_CONTAINS_BUNDLE         (0x20)
#endif

#define IKEEXT_KERB_AUTH_DISABLE_INITIATOR_TOKEN_GENERATION (0x1)
#define IKEEXT_KERB_AUTH_DONT_ACCEPT_EXPLICIT_CREDENTIALS   (0x2)
#if (NTDDI_VERSION >= NTDDI_WIN8)
#define IKEEXT_KERB_AUTH_FORCE_PROXY_ON_INITIATOR           (0x4)
#endif

#define IKEEXT_RESERVED_AUTH_DISABLE_INITIATOR_TOKEN_GENERATION (0x1)

#define IKEEXT_NTLM_V2_AUTH_DONT_ACCEPT_EXPLICIT_CREDENTIALS (0x1)

#define IKEEXT_POLICY_FLAG_DISABLE_DIAGNOSTICS (0x00000001)
#define IKEEXT_POLICY_FLAG_NO_MACHINE_LUID_VERIFY (0x00000002)
#define IKEEXT_POLICY_FLAG_NO_IMPERSONATION_LUID_VERIFY (0x00000004)
#define IKEEXT_POLICY_FLAG_ENABLE_OPTIONAL_DH (0x00000008)

#define IKEEXT_CERT_CREDENTIAL_FLAG_NAP_CERT (0x1)

#if (NTDDI_VERSION >= NTDDI_WIN7)
#define IKEEXT_PSK_FLAG_LOCAL_AUTH_ONLY  (0x1)
#define IKEEXT_PSK_FLAG_REMOTE_AUTH_ONLY (0x2)

#define IKEEXT_EAP_FLAG_LOCAL_AUTH_ONLY   (0x1)
#define IKEEXT_EAP_FLAG_REMOTE_AUTH_ONLY  (0x2)
#endif

#ifndef __IPSEC_V4_UDP_ENCAPSULATION0_FWD_DECLARED
#define __IPSEC_V4_UDP_ENCAPSULATION0_FWD_DECLARED
typedef struct IPSEC_V4_UDP_ENCAPSULATION0_ IPSEC_V4_UDP_ENCAPSULATION0;
#endif

typedef UINT64 IKEEXT_COOKIE;

typedef enum IKEEXT_EM_SA_STATE_ {
    IKEEXT_EM_SA_STATE_NONE = 0,
    IKEEXT_EM_SA_STATE_SENT_ATTS = 1,
    IKEEXT_EM_SA_STATE_SSPI_SENT = 2,
    IKEEXT_EM_SA_STATE_AUTH_COMPLETE = 3,
    IKEEXT_EM_SA_STATE_FINAL = 4,
    IKEEXT_EM_SA_STATE_COMPLETE = 5,
    IKEEXT_EM_SA_STATE_MAX = 6
} IKEEXT_EM_SA_STATE;

typedef enum IKEEXT_SA_ROLE_ {
    IKEEXT_SA_ROLE_INITIATOR = 0,
    IKEEXT_SA_ROLE_RESPONDER = 1,
    IKEEXT_SA_ROLE_MAX = 2
} IKEEXT_SA_ROLE;

typedef enum IKEEXT_AUTHENTICATION_METHOD_TYPE_ {
    IKEEXT_PRESHARED_KEY = 0,
    IKEEXT_CERTIFICATE = 1,
    IKEEXT_KERBEROS = 2,
    IKEEXT_ANONYMOUS = 3,
    IKEEXT_SSL = 4,
    IKEEXT_NTLM_V2 = 5,
    IKEEXT_IPV6_CGA = 6,
    IKEEXT_CERTIFICATE_ECDSA_P256 = 7,
    IKEEXT_CERTIFICATE_ECDSA_P384 = 8,
    IKEEXT_SSL_ECDSA_P256 = 9,
    IKEEXT_SSL_ECDSA_P384 = 10,
    IKEEXT_EAP = 11,
    IKEEXT_RESERVED = 12,
    IKEEXT_AUTHENTICATION_METHOD_TYPE_MAX = 13
} IKEEXT_AUTHENTICATION_METHOD_TYPE;

typedef enum IKEEXT_KEY_MODULE_TYPE_ {
    IKEEXT_KEY_MODULE_IKE = 0,
    IKEEXT_KEY_MODULE_AUTHIP = 1,
    IKEEXT_KEY_MODULE_IKEV2 = 2,
    IKEEXT_KEY_MODULE_MAX = 3
} IKEEXT_KEY_MODULE_TYPE;

typedef enum IKEEXT_MM_SA_STATE_ {
    IKEEXT_MM_SA_STATE_NONE = 0,
    IKEEXT_MM_SA_STATE_SA_SENT = 1,
    IKEEXT_MM_SA_STATE_SSPI_SENT = 2,
    IKEEXT_MM_SA_STATE_FINAL = 3,
    IKEEXT_MM_SA_STATE_FINAL_SENT = 4,
    IKEEXT_MM_SA_STATE_COMPLETE = 5,
    IKEEXT_MM_SA_STATE_MAX = 6
} IKEEXT_MM_SA_STATE;

typedef enum IKEEXT_QM_SA_STATE_ {
    IKEEXT_QM_SA_STATE_NONE = 0,
    IKEEXT_QM_SA_STATE_INITIAL = 1,
    IKEEXT_QM_SA_STATE_FINAL = 2,
    IKEEXT_QM_SA_STATE_COMPLETE = 3,
    IKEEXT_QM_SA_STATE_MAX = 4
} IKEEXT_QM_SA_STATE;

typedef enum IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE_ {
    IKEEXT_IMPERSONATION_NONE = 0,
    IKEEXT_IMPERSONATION_SOCKET_PRINCIPAL = 1,
    IKEEXT_IMPERSONATION_MAX = 2
} IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE;

typedef enum IKEEXT_CERT_CONFIG_TYPE_ {
    IKEEXT_CERT_CONFIG_EXPLICIT_TRUST_LIST = 0,
    IKEEXT_CERT_CONFIG_ENTERPRISE_STORE = 1,
    IKEEXT_CERT_CONFIG_TRUSTED_ROOT_STORE = 2,
    IKEEXT_CERT_CONFIG_UNSPECIFIED = 3,
    IKEEXT_CERT_CONFIG_TYPE_MAX = 4
} IKEEXT_CERT_CONFIG_TYPE;

typedef enum IKEEXT_CIPHER_TYPE_ {
    IKEEXT_CIPHER_DES = 0,
    IKEEXT_CIPHER_3DES = 1,
    IKEEXT_CIPHER_AES_128 = 2,
    IKEEXT_CIPHER_AES_192 = 3,
    IKEEXT_CIPHER_AES_256 = 4,
    IKEEXT_CIPHER_TYPE_MAX = 5
} IKEEXT_CIPHER_TYPE;

typedef enum IKEEXT_INTEGRITY_TYPE_ {
    IKEEXT_INTEGRITY_MD5 = 0,
    IKEEXT_INTEGRITY_SHA1 = 1,
    IKEEXT_INTEGRITY_SHA_256 = 2,
    IKEEXT_INTEGRITY_SHA_384 = 3,
    IKEEXT_INTEGRITY_TYPE_MAX = 4
} IKEEXT_INTEGRITY_TYPE;

typedef enum IKEEXT_DH_GROUP_ {
    IKEEXT_DH_GROUP_NONE = 0,
    IKEEXT_DH_GROUP_1 = 1,
    IKEEXT_DH_GROUP_2 = 2,
    IKEEXT_DH_GROUP_14 = 3,
    IKEEXT_DH_GROUP_2048 = IKEEXT_DH_GROUP_14,
    IKEEXT_DH_ECP_256 = 4,
    IKEEXT_DH_ECP_384 = 5,
    IKEEXT_DH_GROUP_24 = 6,
    IKEEXT_DH_GROUP_MAX = 7
} IKEEXT_DH_GROUP;

typedef struct IKEEXT_CERT_ROOT_CONFIG0_ {
    FWP_BYTE_BLOB certData;
    UINT32 flags;
} IKEEXT_CERT_ROOT_CONFIG0;

typedef struct IKEEXT_KERBEROS_AUTHENTICATION0__ {
    UINT32 flags;
} IKEEXT_KERBEROS_AUTHENTICATION0;

typedef struct IKEEXT_NTLM_V2_AUTHENTICATION0__ {
    UINT32 flags;
} IKEEXT_NTLM_V2_AUTHENTICATION0;

typedef struct IKEEXT_PRESHARED_KEY_AUTHENTICATION0__ {
    FWP_BYTE_BLOB presharedKey;
} IKEEXT_PRESHARED_KEY_AUTHENTICATION0;

typedef struct IKEEXT_PRESHARED_KEY_AUTHENTICATION1__ {
    FWP_BYTE_BLOB presharedKey;
    UINT32 flags;
} IKEEXT_PRESHARED_KEY_AUTHENTICATION1;

typedef struct IKEEXT_CERTIFICATE_AUTHENTICATION0_ {
    IKEEXT_CERT_CONFIG_TYPE inboundConfigType;
    __C89_NAMELESS union {
        __C89_NAMELESS struct {
            UINT32 inboundRootArraySize;
            IKEEXT_CERT_ROOT_CONFIG0 *inboundRootArray;
        } __C89_NAMELESSSTRUCTNAME;
        IKEEXT_CERT_ROOT_CONFIG0 *inboundEnterpriseStoreConfig;
        IKEEXT_CERT_ROOT_CONFIG0 *inboundTrustedRootStoreConfig;
    } __C89_NAMELESSUNIONNAME1;
    IKEEXT_CERT_CONFIG_TYPE outboundConfigType;
    __C89_NAMELESS union {
        __C89_NAMELESS struct {
            UINT32 outboundRootArraySize;
            IKEEXT_CERT_ROOT_CONFIG0 *outboundRootArray;
        } __C89_NAMELESSSTRUCTNAME;
        IKEEXT_CERT_ROOT_CONFIG0 *outboundEnterpriseStoreConfig;
        IKEEXT_CERT_ROOT_CONFIG0 *outboundTrustedRootStoreConfig;
    } __C89_NAMELESSUNIONNAME2;
    UINT32 flags;
} IKEEXT_CERTIFICATE_AUTHENTICATION0;

#if NTDDI_VERSION >= NTDDI_WIN7
typedef struct IKEEXT_CERTIFICATE_AUTHENTICATION1_ {
    IKEEXT_CERT_CONFIG_TYPE inboundConfigType;
    __C89_NAMELESS union {
        __C89_NAMELESS struct {
            UINT32 inboundRootArraySize;
            IKEEXT_CERT_ROOT_CONFIG0 *inboundRootArray;
        } __C89_NAMELESSSTRUCTNAME;
        IKEEXT_CERT_ROOT_CONFIG0 *inboundEnterpriseStoreConfig;
        IKEEXT_CERT_ROOT_CONFIG0 *inboundTrustedRootStoreConfig;
    } __C89_NAMELESSUNIONNAME1;
    IKEEXT_CERT_CONFIG_TYPE outboundConfigType;
    __C89_NAMELESS union {
        __C89_NAMELESS struct {
            UINT32 outboundRootArraySize;
            IKEEXT_CERT_ROOT_CONFIG0 *outboundRootArray;
        } __C89_NAMELESSSTRUCTNAME;
        IKEEXT_CERT_ROOT_CONFIG0 *outboundEnterpriseStoreConfig;
        IKEEXT_CERT_ROOT_CONFIG0 *outboundTrustedRootStoreConfig;
    } __C89_NAMELESSUNIONNAME2;
    UINT32 flags;
    FWP_BYTE_BLOB localCertLocationUrl;
} IKEEXT_CERTIFICATE_AUTHENTICATION1;
#endif

#if (NTDDI_VERSION >= NTDDI_WIN8)
typedef enum IKEEXT_CERT_CRITERIA_NAME_TYPE_ {
    IKEEXT_CERT_CRITERIA_DNS = 0,
    IKEEXT_CERT_CRITERIA_UPN = 1,
    IKEEXT_CERT_CRITERIA_RFC822 = 2,
    IKEEXT_CERT_CRITERIA_CN = 3,
    IKEEXT_CERT_CRITERIA_OU = 4,
    IKEEXT_CERT_CRITERIA_O = 5,
    IKEEXT_CERT_CRITERIA_DC = 6,
    IKEEXT_CERT_CRITERIA_NAME_TYPE_MAX = 7
} IKEEXT_CERT_CRITERIA_NAME_TYPE;

typedef struct IKEEXT_CERT_EKUS0_ {
    ULONG numEku;
    LPSTR *eku;
} IKEEXT_CERT_EKUS0;

typedef struct IKEEXT_CERT_NAME0_ {
    IKEEXT_CERT_CRITERIA_NAME_TYPE nameType;
    LPWSTR certName;
} IKEEXT_CERT_NAME0;

typedef struct IKEEXT_CERTIFICATE_CRITERIA0_ {
    FWP_BYTE_BLOB certData;
    FWP_BYTE_BLOB certHash;
    IKEEXT_CERT_EKUS0 *eku;
    IKEEXT_CERT_NAME0 *name;
    UINT32 flags;
} IKEEXT_CERTIFICATE_CRITERIA0;

typedef struct IKEEXT_CERTIFICATE_AUTHENTICATION2_ {
    IKEEXT_CERT_CONFIG_TYPE inboundConfigType;
    __C89_NAMELESS union {
        __C89_NAMELESS struct {
            UINT32 inboundRootArraySize;
            IKEEXT_CERTIFICATE_CRITERIA0 *inboundRootCriteria;
        } __C89_NAMELESSSTRUCTNAME1;
        __C89_NAMELESS struct {
            UINT32 inboundEnterpriseStoreArraySize;
            IKEEXT_CERTIFICATE_CRITERIA0 *inboundEnterpriseStoreCriteria;
        } __C89_NAMELESSSTRUCTNAME2;
        __C89_NAMELESS struct {
            UINT32 inboundRootStoreArraySize;
            IKEEXT_CERTIFICATE_CRITERIA0 *inboundTrustedRootStoreCriteria;
        } __C89_NAMELESSSTRUCTNAME3;
    } __C89_NAMELESSUNIONNAME1;
    IKEEXT_CERT_CONFIG_TYPE outboundConfigType;
    __C89_NAMELESS union {
        __C89_NAMELESS struct {
            UINT32 outboundRootArraySize;
            IKEEXT_CERTIFICATE_CRITERIA0 *outboundRootCriteria;
        } __C89_NAMELESSSTRUCTNAME1;
        __C89_NAMELESS struct {
            UINT32 outboundEnterpriseStoreArraySize;
            IKEEXT_CERTIFICATE_CRITERIA0 *outboundEnterpriseStoreCriteria;
        } __C89_NAMELESSSTRUCTNAME2;
        __C89_NAMELESS struct {
            UINT32 outboundRootStoreArraySize;
            IKEEXT_CERTIFICATE_CRITERIA0 *outboundTrustedRootStoreCriteria;
        } __C89_NAMELESSSTRUCTNAME3;
    } __C89_NAMELESSUNIONNAME2;
    UINT32 flags;
    FWP_BYTE_BLOB localCertLocationUrl;
} IKEEXT_CERTIFICATE_AUTHENTICATION2;
#endif

typedef struct IKEEXT_IPV6_CGA_AUTHENTICATION0_ {
    wchar_t *keyContainerName;
    wchar_t *cspName;
    UINT32 cspType;
    FWP_BYTE_ARRAY16 cgaModifier;
    BYTE cgaCollisionCount;
} IKEEXT_IPV6_CGA_AUTHENTICATION0;

#if (NTDDI_VERSION >= NTDDI_WIN8)
typedef struct IKEEXT_KERBEROS_AUTHENTICATION1__ {
    UINT32 flags;
    wchar_t *proxyServer;
} IKEEXT_KERBEROS_AUTHENTICATION1;
#endif

typedef struct IKEEXT_RESERVED_AUTHENTICATION0__ {
    UINT32 flags;
} IKEEXT_RESERVED_AUTHENTICATION0;

#if (NTDDI_VERSION >= NTDDI_WIN7)
typedef struct IKEEXT_EAP_AUTHENTICATION0__ {
    UINT32 flags;
} IKEEXT_EAP_AUTHENTICATION0;
#endif

typedef struct IKEEXT_AUTHENTICATION_METHOD0_ {
    IKEEXT_AUTHENTICATION_METHOD_TYPE authenticationMethodType;
    __C89_NAMELESS union {
        IKEEXT_PRESHARED_KEY_AUTHENTICATION0 presharedKeyAuthentication;
        IKEEXT_CERTIFICATE_AUTHENTICATION0 certificateAuthentication;
        IKEEXT_KERBEROS_AUTHENTICATION0 kerberosAuthentication;
        IKEEXT_NTLM_V2_AUTHENTICATION0 ntlmV2Authentication;
        IKEEXT_CERTIFICATE_AUTHENTICATION0 sslAuthentication;
        IKEEXT_IPV6_CGA_AUTHENTICATION0 cgaAuthentication;
    } __C89_NAMELESSUNIONNAME;
} IKEEXT_AUTHENTICATION_METHOD0;

#if (NTDDI_VERSION >= NTDDI_WIN7)
typedef struct IKEEXT_AUTHENTICATION_METHOD1_ {
    IKEEXT_AUTHENTICATION_METHOD_TYPE authenticationMethodType;
    __C89_NAMELESS union {
        IKEEXT_PRESHARED_KEY_AUTHENTICATION1 presharedKeyAuthentication;
        IKEEXT_CERTIFICATE_AUTHENTICATION1 certificateAuthentication;
        IKEEXT_KERBEROS_AUTHENTICATION0 kerberosAuthentication;
        IKEEXT_NTLM_V2_AUTHENTICATION0 ntlmV2Authentication;
        IKEEXT_CERTIFICATE_AUTHENTICATION1 sslAuthentication;
        IKEEXT_IPV6_CGA_AUTHENTICATION0 cgaAuthentication;
        IKEEXT_EAP_AUTHENTICATION0 eapAuthentication;
    } __C89_NAMELESSUNIONNAME;
} IKEEXT_AUTHENTICATION_METHOD1;
#endif

#if (NTDDI_VERSION >= NTDDI_WIN8)
typedef struct IKEEXT_AUTHENTICATION_METHOD2_ {
    IKEEXT_AUTHENTICATION_METHOD_TYPE authenticationMethodType;
    __C89_NAMELESS union {
        IKEEXT_PRESHARED_KEY_AUTHENTICATION1 presharedKeyAuthentication;
        IKEEXT_CERTIFICATE_AUTHENTICATION2 certificateAuthentication;
        IKEEXT_KERBEROS_AUTHENTICATION1 kerberosAuthentication;
        IKEEXT_RESERVED_AUTHENTICATION0 reservedAuthentication;
        IKEEXT_NTLM_V2_AUTHENTICATION0 ntlmV2Authentication;
        IKEEXT_CERTIFICATE_AUTHENTICATION2 sslAuthentication;
        IKEEXT_IPV6_CGA_AUTHENTICATION0 cgaAuthentication;
        IKEEXT_EAP_AUTHENTICATION0 eapAuthentication;
    } __C89_NAMELESSUNIONNAME;
} IKEEXT_AUTHENTICATION_METHOD2;
#endif

typedef struct IKEEXT_CIPHER_ALGORITHM0_ {
    IKEEXT_CIPHER_TYPE algoIdentifier;
    UINT32 keyLen;
    UINT32 rounds;
} IKEEXT_CIPHER_ALGORITHM0;

typedef struct IKEEXT_INTEGRITY_ALGORITHM0_ {
    IKEEXT_INTEGRITY_TYPE algoIdentifier;
} IKEEXT_INTEGRITY_ALGORITHM0;

typedef struct IKEEXT_PROPOSAL0_ {
    IKEEXT_CIPHER_ALGORITHM0 cipherAlgorithm;
    IKEEXT_INTEGRITY_ALGORITHM0 integrityAlgorithm;
    UINT32 maxLifetimeSeconds;
    IKEEXT_DH_GROUP dhGroup;
    UINT32 quickModeLimit;
} IKEEXT_PROPOSAL0;

typedef struct IKEEXT_POLICY0_ {
    UINT32 softExpirationTime;
    UINT32 numAuthenticationMethods;
    IKEEXT_AUTHENTICATION_METHOD0 *authenticationMethods;
    IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE initiatorImpersonationType;
    UINT32 numIkeProposals;
    IKEEXT_PROPOSAL0 *ikeProposals;
    UINT32 flags;
    UINT32 maxDynamicFilters;
} IKEEXT_POLICY0;

#if (NTDDI_VERSION >= NTDDI_WIN7)
typedef struct IKEEXT_POLICY1_ {
    UINT32 softExpirationTime;
    UINT32 numAuthenticationMethods;
    IKEEXT_AUTHENTICATION_METHOD1 *authenticationMethods;
    IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE initiatorImpersonationType;
    UINT32 numIkeProposals;
    IKEEXT_PROPOSAL0 *ikeProposals;
    UINT32 flags;
    UINT32 maxDynamicFilters;
    UINT32 retransmitDurationSecs;
} IKEEXT_POLICY1;
#endif

#if (NTDDI_VERSION >= NTDDI_WIN8)
typedef struct IKEEXT_POLICY2_ {
    UINT32 softExpirationTime;
    UINT32 numAuthenticationMethods;
    IKEEXT_AUTHENTICATION_METHOD2 *authenticationMethods;
    IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE initiatorImpersonationType;
    UINT32 numIkeProposals;
    IKEEXT_PROPOSAL0 *ikeProposals;
    UINT32 flags;
    UINT32 maxDynamicFilters;
    UINT32 retransmitDurationSecs;
} IKEEXT_POLICY2;
#endif

typedef struct IKEEXT_EM_POLICY0_ {
    UINT32 numAuthenticationMethods;
    IKEEXT_AUTHENTICATION_METHOD0 *authenticationMethods;
    IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE initiatorImpersonationType;
} IKEEXT_EM_POLICY0;

#if (NTDDI_VERSION >= NTDDI_WIN7)
typedef struct IKEEXT_EM_POLICY1_ {
    UINT32 numAuthenticationMethods;
    IKEEXT_AUTHENTICATION_METHOD1 *authenticationMethods;
    IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE initiatorImpersonationType;
} IKEEXT_EM_POLICY1;
#endif

#if (NTDDI_VERSION >= NTDDI_WIN8)
typedef struct IKEEXT_EM_POLICY2_ {
    UINT32 numAuthenticationMethods;
    IKEEXT_AUTHENTICATION_METHOD2 *authenticationMethods;
    IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE initiatorImpersonationType;
} IKEEXT_EM_POLICY2;
#endif

typedef struct IKEEXT_IP_VERSION_SPECIFIC_KEYMODULE_STATISTICS0_ {
    UINT32 currentActiveMainModes;
    UINT32 totalMainModesStarted;
    UINT32 totalSuccessfulMainModes;
    UINT32 totalFailedMainModes;
    UINT32 totalResponderMainModes;
    UINT32 currentNewResponderMainModes;
    UINT32 currentActiveQuickModes;
    UINT32 totalQuickModesStarted;
    UINT32 totalSuccessfulQuickModes;
    UINT32 totalFailedQuickModes;
    UINT32 totalAcquires;
    UINT32 totalReinitAcquires;
    UINT32 currentActiveExtendedModes;
    UINT32 totalExtendedModesStarted;
    UINT32 totalSuccessfulExtendedModes;
    UINT32 totalFailedExtendedModes;
    UINT32 totalImpersonationExtendedModes;
    UINT32 totalImpersonationMainModes;
} IKEEXT_IP_VERSION_SPECIFIC_KEYMODULE_STATISTICS0;

#if (NTDDI_VERSION >= NTDDI_WIN7)
typedef struct IKEEXT_IP_VERSION_SPECIFIC_KEYMODULE_STATISTICS1_ {
    UINT32 currentActiveMainModes;
    UINT32 totalMainModesStarted;
    UINT32 totalSuccessfulMainModes;
    UINT32 totalFailedMainModes;
    UINT32 totalResponderMainModes;
    UINT32 currentNewResponderMainModes;
    UINT32 currentActiveQuickModes;
    UINT32 totalQuickModesStarted;
    UINT32 totalSuccessfulQuickModes;
    UINT32 totalFailedQuickModes;
    UINT32 totalAcquires;
    UINT32 totalReinitAcquires;
    UINT32 currentActiveExtendedModes;
    UINT32 totalExtendedModesStarted;
    UINT32 totalSuccessfulExtendedModes;
    UINT32 totalFailedExtendedModes;
    UINT32 totalImpersonationExtendedModes;
    UINT32 totalImpersonationMainModes;
} IKEEXT_IP_VERSION_SPECIFIC_KEYMODULE_STATISTICS1;
#endif

typedef struct IKEEXT_KEYMODULE_STATISTICS0_ {
    IKEEXT_IP_VERSION_SPECIFIC_KEYMODULE_STATISTICS0 v4Statistics;
    IKEEXT_IP_VERSION_SPECIFIC_KEYMODULE_STATISTICS0 v6Statistics;
    UINT32 errorFrequencyTable[97];
    UINT32 mainModeNegotiationTime;
    UINT32 quickModeNegotiationTime;
    UINT32 extendedModeNegotiationTime;
} IKEEXT_KEYMODULE_STATISTICS0;

#if (NTDDI_VERSION >= NTDDI_WIN7)
typedef struct IKEEXT_KEYMODULE_STATISTICS1_ {
    IKEEXT_IP_VERSION_SPECIFIC_KEYMODULE_STATISTICS1 v4Statistics;
    IKEEXT_IP_VERSION_SPECIFIC_KEYMODULE_STATISTICS1 v6Statistics;
    UINT32 errorFrequencyTable[97];
    UINT32 mainModeNegotiationTime;
    UINT32 quickModeNegotiationTime;
    UINT32 extendedModeNegotiationTime;
} IKEEXT_KEYMODULE_STATISTICS1;
#endif

typedef struct IKEEXT_IP_VERSION_SPECIFIC_COMMON_STATISTICS0_ {
    UINT32 totalSocketReceiveFailures;
    UINT32 totalSocketSendFailures;
} IKEEXT_IP_VERSION_SPECIFIC_COMMON_STATISTICS0;

#if (NTDDI_VERSION >= NTDDI_WIN7)
typedef struct IKEEXT_IP_VERSION_SPECIFIC_COMMON_STATISTICS1_ {
    UINT32 totalSocketReceiveFailures;
    UINT32 totalSocketSendFailures;
} IKEEXT_IP_VERSION_SPECIFIC_COMMON_STATISTICS1;
#endif

typedef struct IKEEXT_COMMON_STATISTICS0_ {
    IKEEXT_IP_VERSION_SPECIFIC_COMMON_STATISTICS0 v4Statistics;
    IKEEXT_IP_VERSION_SPECIFIC_COMMON_STATISTICS0 v6Statistics;
    UINT32 totalPacketsReceived;
    UINT32 totalInvalidPacketsReceived;
    UINT32 currentQueuedWorkitems;
} IKEEXT_COMMON_STATISTICS0;

#if (NTDDI_VERSION >= NTDDI_WIN7)
typedef struct IKEEXT_COMMON_STATISTICS1_ {
    IKEEXT_IP_VERSION_SPECIFIC_COMMON_STATISTICS1 v4Statistics;
    IKEEXT_IP_VERSION_SPECIFIC_COMMON_STATISTICS1 v6Statistics;
    UINT32 totalPacketsReceived;
    UINT32 totalInvalidPacketsReceived;
    UINT32 currentQueuedWorkitems;
} IKEEXT_COMMON_STATISTICS1;
#endif

typedef struct IKEEXT_STATISTICS0_ {
    IKEEXT_KEYMODULE_STATISTICS0 ikeStatistics;
    IKEEXT_KEYMODULE_STATISTICS0 authipStatistics;
    IKEEXT_COMMON_STATISTICS0 commonStatistics;
} IKEEXT_STATISTICS0;

#if (NTDDI_VERSION >= NTDDI_WIN7)
typedef struct IKEEXT_STATISTICS1_ {
    IKEEXT_KEYMODULE_STATISTICS1 ikeStatistics;
    IKEEXT_KEYMODULE_STATISTICS1 authipStatistics;
    IKEEXT_KEYMODULE_STATISTICS1 ikeV2Statistics;
    IKEEXT_COMMON_STATISTICS1 commonStatistics;
} IKEEXT_STATISTICS1;
#endif

typedef struct IKEEXT_TRAFFIC0_ {
    FWP_IP_VERSION ipVersion;
    __C89_NAMELESS union {
        UINT32 localV4Address;
        UINT8 localV6Address[16];
    } __C89_NAMELESSUNIONNAME1;
    __C89_NAMELESS union {
        UINT32 remoteV4Address;
        UINT8 remoteV6Address[16];
    } __C89_NAMELESSUNIONNAME2;
    UINT64 authIpFilterId;
} IKEEXT_TRAFFIC0;

typedef struct IKEEXT_COOKIE_PAIR0_ {
    IKEEXT_COOKIE initiator;
    IKEEXT_COOKIE responder;
} IKEEXT_COOKIE_PAIR0;

typedef struct IKEEXT_CERTIFICATE_CREDENTIAL0_ {
    FWP_BYTE_BLOB subjectName;
    FWP_BYTE_BLOB certHash;
    UINT32 flags;
} IKEEXT_CERTIFICATE_CREDENTIAL0;

typedef struct IKEEXT_NAME_CREDENTIAL0_ {
    wchar_t *principalName;
} IKEEXT_NAME_CREDENTIAL0;
typedef struct IKEEXT_CREDENTIAL0_ {
    IKEEXT_AUTHENTICATION_METHOD_TYPE authenticationMethodType;
    IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE impersonationType;
    __C89_NAMELESS union {
        IKEEXT_PRESHARED_KEY_AUTHENTICATION0 *presharedKey;
        IKEEXT_CERTIFICATE_CREDENTIAL0 *certificate;
        IKEEXT_NAME_CREDENTIAL0 *name;
    } __C89_NAMELESSUNIONNAME;
} IKEEXT_CREDENTIAL0;

typedef struct IKEEXT_CREDENTIAL_PAIR0_ {
    IKEEXT_CREDENTIAL0 localCredentials;
    IKEEXT_CREDENTIAL0 peerCredentials;
} IKEEXT_CREDENTIAL_PAIR0;

typedef struct IKEEXT_CREDENTIALS0_ {
    UINT32 numCredentials;
    IKEEXT_CREDENTIAL_PAIR0 *credentials;
} IKEEXT_CREDENTIALS0;

typedef struct IKEEXT_SA_DETAILS0_ {
    UINT64 saId;
    IKEEXT_KEY_MODULE_TYPE keyModuleType;
    FWP_IP_VERSION ipVersion;
    __C89_NAMELESS union {
        IPSEC_V4_UDP_ENCAPSULATION0 *v4UdpEncapsulation;
    } __C89_NAMELESSUNIONNAME;
    IKEEXT_TRAFFIC0 ikeTraffic;
    IKEEXT_PROPOSAL0 ikeProposal;
    IKEEXT_COOKIE_PAIR0 cookiePair;
    IKEEXT_CREDENTIALS0 ikeCredentials;
    GUID ikePolicyKey;
    UINT64 virtualIfTunnelId;
} IKEEXT_SA_DETAILS0;

#if (NTDDI_VERSION >= NTDDI_WIN7)
typedef struct IKEEXT_CERTIFICATE_CREDENTIAL1_ {
    FWP_BYTE_BLOB subjectName;
    FWP_BYTE_BLOB certHash;
    UINT32 flags;
    FWP_BYTE_BLOB certificate;
} IKEEXT_CERTIFICATE_CREDENTIAL1;

typedef struct IKEEXT_CREDENTIAL1_ {
    IKEEXT_AUTHENTICATION_METHOD_TYPE authenticationMethodType;
    IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE impersonationType;
    __C89_NAMELESS union {
        IKEEXT_PRESHARED_KEY_AUTHENTICATION1 *presharedKey;
        IKEEXT_CERTIFICATE_CREDENTIAL1 *certificate;
        IKEEXT_NAME_CREDENTIAL0 *name;
    } __C89_NAMELESSUNIONNAME;
} IKEEXT_CREDENTIAL1;

typedef struct IKEEXT_CREDENTIAL_PAIR1_ {
    IKEEXT_CREDENTIAL1 localCredentials;
    IKEEXT_CREDENTIAL1 peerCredentials;
} IKEEXT_CREDENTIAL_PAIR1;

typedef struct IKEEXT_CREDENTIALS1_ {
    UINT32 numCredentials;
    IKEEXT_CREDENTIAL_PAIR1 *credentials;
} IKEEXT_CREDENTIALS1;

typedef struct IKEEXT_SA_DETAILS1_ {
    UINT64 saId;
    IKEEXT_KEY_MODULE_TYPE keyModuleType;
    FWP_IP_VERSION ipVersion;
    __C89_NAMELESS union {
        IPSEC_V4_UDP_ENCAPSULATION0 *v4UdpEncapsulation;
    } __C89_NAMELESSUNIONNAME;
    IKEEXT_TRAFFIC0 ikeTraffic;
    IKEEXT_PROPOSAL0 ikeProposal;
    IKEEXT_COOKIE_PAIR0 cookiePair;
    IKEEXT_CREDENTIALS1 ikeCredentials;
    GUID ikePolicyKey;
    UINT64 virtualIfTunnelId;
    FWP_BYTE_BLOB correlationKey;
} IKEEXT_SA_DETAILS1;
#endif

#if (NTDDI_VERSION >= NTDDI_WIN8)
typedef struct IKEEXT_CREDENTIAL2_ {
    IKEEXT_AUTHENTICATION_METHOD_TYPE authenticationMethodType;
    IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE impersonationType;
    __C89_NAMELESS union {
        IKEEXT_PRESHARED_KEY_AUTHENTICATION1 *presharedKey;
        IKEEXT_CERTIFICATE_CREDENTIAL1 *certificate;
        IKEEXT_NAME_CREDENTIAL0 *name;
    } __C89_NAMELESSUNIONNAME;
} IKEEXT_CREDENTIAL2;

typedef struct IKEEXT_CREDENTIAL_PAIR2_ {
    IKEEXT_CREDENTIAL2 localCredentials;
    IKEEXT_CREDENTIAL2 peerCredentials;
} IKEEXT_CREDENTIAL_PAIR2;

typedef struct IKEEXT_CREDENTIALS2_ {
    UINT32 numCredentials;
    IKEEXT_CREDENTIAL_PAIR2 *credentials;
} IKEEXT_CREDENTIALS2;

typedef struct IKEEXT_SA_DETAILS2_ {
    UINT64 saId;
    IKEEXT_KEY_MODULE_TYPE keyModuleType;
    FWP_IP_VERSION ipVersion;
    __C89_NAMELESS union {
        IPSEC_V4_UDP_ENCAPSULATION0 *v4UdpEncapsulation;
    } __C89_NAMELESSUNIONNAME;
    IKEEXT_TRAFFIC0 ikeTraffic;
    IKEEXT_PROPOSAL0 ikeProposal;
    IKEEXT_COOKIE_PAIR0 cookiePair;
    IKEEXT_CREDENTIALS2 ikeCredentials;
    GUID ikePolicyKey;
    UINT64 virtualIfTunnelId;
    FWP_BYTE_BLOB correlationKey;
} IKEEXT_SA_DETAILS2;
#endif

typedef struct IKEEXT_SA_ENUM_TEMPLATE0_ {
    FWP_CONDITION_VALUE0 localSubNet;
    FWP_CONDITION_VALUE0 remoteSubNet;
    FWP_BYTE_BLOB localMainModeCertHash;
} IKEEXT_SA_ENUM_TEMPLATE0;

#endif /* WINAPI_PARTITION_DESKTOP.  */
/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __iketypes_h__ */