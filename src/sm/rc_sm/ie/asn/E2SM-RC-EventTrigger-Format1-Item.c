/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm_rc_v1_03_modified.asn"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#include "E2SM-RC-EventTrigger-Format1-Item.h"

#include "EventTrigger-UE-Info.h"
#include "EventTrigger-UEevent-Info.h"
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_messageDirection_constr_4 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static const asn_INTEGER_enum_map_t asn_MAP_messageDirection_value2enum_4[] = {
	{ 0,	8,	"incoming" },
	{ 1,	8,	"outgoing" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_messageDirection_enum2value_4[] = {
	0,	/* incoming(0) */
	1	/* outgoing(1) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_messageDirection_specs_4 = {
	asn_MAP_messageDirection_value2enum_4,	/* "tag" => N; sorted by tag */
	asn_MAP_messageDirection_enum2value_4,	/* N => "tag"; sorted by N */
	2,	/* Number of elements in the maps */
	3,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_messageDirection_tags_4[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_messageDirection_4 = {
	"messageDirection",
	"messageDirection",
	&asn_OP_NativeEnumerated,
	asn_DEF_messageDirection_tags_4,
	sizeof(asn_DEF_messageDirection_tags_4)
		/sizeof(asn_DEF_messageDirection_tags_4[0]) - 1, /* 1 */
	asn_DEF_messageDirection_tags_4,	/* Same as above */
	sizeof(asn_DEF_messageDirection_tags_4)
		/sizeof(asn_DEF_messageDirection_tags_4[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_messageDirection_constr_4,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_messageDirection_specs_4	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_E2SM_RC_EventTrigger_Format1_Item_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_EventTrigger_Format1_Item, ric_eventTriggerCondition_ID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RIC_EventTriggerCondition_ID,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"ric-eventTriggerCondition-ID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_EventTrigger_Format1_Item, messageType),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_MessageType_Choice,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"messageType"
		},
	{ ATF_POINTER, 4, offsetof(struct E2SM_RC_EventTrigger_Format1_Item, messageDirection),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_messageDirection_4,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"messageDirection"
		},
	{ ATF_POINTER, 3, offsetof(struct E2SM_RC_EventTrigger_Format1_Item, associatedUEInfo),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_EventTrigger_UE_Info,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"associatedUEInfo"
		},
	{ ATF_POINTER, 2, offsetof(struct E2SM_RC_EventTrigger_Format1_Item, associatedUEEvent),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_EventTrigger_UEevent_Info,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"associatedUEEvent"
		},
	{ ATF_POINTER, 1, offsetof(struct E2SM_RC_EventTrigger_Format1_Item, logicalOR),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LogicalOR,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"logicalOR"
		},
};
static const int asn_MAP_E2SM_RC_EventTrigger_Format1_Item_oms_1[] = { 2, 3, 4, 5 };
static const ber_tlv_tag_t asn_DEF_E2SM_RC_EventTrigger_Format1_Item_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_RC_EventTrigger_Format1_Item_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ric-eventTriggerCondition-ID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* messageType */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* messageDirection */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* associatedUEInfo */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* associatedUEEvent */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 } /* logicalOR */
};
asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_EventTrigger_Format1_Item_specs_1 = {
	sizeof(struct E2SM_RC_EventTrigger_Format1_Item),
	offsetof(struct E2SM_RC_EventTrigger_Format1_Item, _asn_ctx),
	asn_MAP_E2SM_RC_EventTrigger_Format1_Item_tag2el_1,
	6,	/* Count of tags in the map */
	asn_MAP_E2SM_RC_EventTrigger_Format1_Item_oms_1,	/* Optional members */
	4, 0,	/* Root/Additions */
	6,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_EventTrigger_Format1_Item = {
	"E2SM-RC-EventTrigger-Format1-Item",
	"E2SM-RC-EventTrigger-Format1-Item",
	&asn_OP_SEQUENCE,
	asn_DEF_E2SM_RC_EventTrigger_Format1_Item_tags_1,
	sizeof(asn_DEF_E2SM_RC_EventTrigger_Format1_Item_tags_1)
		/sizeof(asn_DEF_E2SM_RC_EventTrigger_Format1_Item_tags_1[0]), /* 1 */
	asn_DEF_E2SM_RC_EventTrigger_Format1_Item_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2SM_RC_EventTrigger_Format1_Item_tags_1)
		/sizeof(asn_DEF_E2SM_RC_EventTrigger_Format1_Item_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_E2SM_RC_EventTrigger_Format1_Item_1,
	6,	/* Elements count */
	&asn_SPC_E2SM_RC_EventTrigger_Format1_Item_specs_1	/* Additional specs */
};

