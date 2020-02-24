#ifndef __RT5036_PMIC_H__
#define __RT5036_PMIC_H__
#include <power/pmic.h>
#include <fdtdec.h>

#define COMPAT_ROCKCHIP_RT5036  "rt,rt5036"
#define RT5036_I2C_ADDR 		0x38
#define RT5036_I2C_SPEED		100000
#define RT5036_NUM_REGULATORS		10

enum {
	RT5036_REG_DEVID,
	RT5036_REG_RANGE1START = RT5036_REG_DEVID,
	RT5036_REG_CHGCTL1,
	RT5036_REG_CHGCTL2,
	RT5036_REG_RESV1,
	RT5036_REG_CHGCTL3,
	RT5036_REG_CHGCTL4,
	RT5036_REG_CHGCTL5,
	RT5036_REG_CHGCTL6,
	RT5036_REG_CHGCTL7,
	RT5036_REG_RSTCHG,
	RT5036_REG_RANGE1END = RT5036_REG_RSTCHG,
	RT5036_REG_CHGIRQ1 = 0x10,
	RT5036_REG_RANGE2START = RT5036_REG_CHGIRQ1,
	RT5036_REG_CHGIRQ2,
	RT5036_REG_CHGIRQ3,
	RT5036_REG_CHGIRQMASK1,
	RT5036_REG_CHGIRQMASK2,
	RT5036_REG_CHGIRQMASK3,
	RT5036_REG_CHGSTAT1,
	RT5036_REG_CHGSTAT2,
	RT5036_REG_CHGSTAT2MASK,
	RT5036_REG_RANGE2END = RT5036_REG_CHGSTAT2MASK,
	RT5036_REG_BUCKVN1 = 0x41,
	RT5036_REG_RANGE3START = RT5036_REG_BUCKVN1,
	RT5036_REG_BUCKVN2,
	RT5036_REG_BUCKVN3,
	RT5036_REG_BUCKVN4,
	RT5036_REG_BUCKVRCN,
	RT5036_REG_BUCKVRCNEN,
	RT5036_REG_BUCKMODE,
	RT5036_REG_LDOVN1,
	RT5036_REG_LDOVN2,
	RT5036_REG_LDOVN3,
	RT5036_REG_LDOVN4,
	RT5036_REG_LDOVRCN,
	RT5036_REG_LDOVRCNEN,
	RT5036_REG_LDOMODE,
	RT5036_REG_BUCKLDONEN,
	RT5036_REG_LSWEN,
	RT5036_REG_MISC1,
	RT5036_REG_MISC2,
	RT5036_REG_MISC3,
	RT5036_REG_MISC4,
	RT5036_REG_MISC5,
	RT5036_REG_ONOFFEVENT,
	RT5036_REG_BUCKLDOIRQ,
	RT5036_REG_LSWBASEIRQ,
	RT5036_REG_PWRKEYIRQ,
	RT5036_REG_BUCKLDOIRQMASK,
	RT5036_REG_LSWBASEIRQMASK,
	RT5036_REG_PWRKEYIRQMASK,
	RT5036_REG_RANGE3END = RT5036_REG_PWRKEYIRQMASK,
	RT5036_REG_MISC6 = 0x65,
	RT5036_REG_RANGE4START = RT5036_REG_MISC6,
	RT5036_REG_RANGE4END = RT5036_REG_MISC6,
	RT5036_REG_BUCKVS1 = 0x71,
	RT5036_REG_RANGE5START = RT5036_REG_BUCKVS1,
	RT5036_REG_BUCKVS2,
	RT5036_REG_BUCKVS3,
	RT5036_REG_BUCKVS4,
	RT5036_REG_BUCKVRCS,
	RT5036_REG_BUCKVRCSEN,
	RT5036_REG_RESV2,
	RT5036_REG_LDOVS1,
	RT5036_REG_LDOVS2,
	RT5036_REG_LDOVS3,
	RT5036_REG_LDOVS4,
	RT5036_REG_LDOVRCS,
	RT5036_REG_LDOVRCSEN,
	RT5036_REG_RESV3,
	RT5036_REG_BUCKLDOSEN,
	RT5036_REG_LSWVN2,
	RT5036_REG_LSWVN1,
	RT5036_REG_LSWVS2,
	RT5036_REG_LSWVS1,
	RT5036_REG_LSWVRC,
	RT5036_REG_LSWVRCEN,
	RT5036_REG_BUCKOCPSEL,
	RT5036_REG_RANGE5END = RT5036_REG_BUCKOCPSEL,
	RT5036_REG_RTCADJ = 0x90,
	RT5036_REG_RANGE6START = RT5036_REG_RTCADJ,
	RT5036_REG_RTCTSEC,
	RT5036_REG_RTCTMINUTE,
	RT5036_REG_RTCTHOUR,
	RT5036_REG_RTCTYEAR,
	RT5036_REG_RTCTMON,
	RT5036_REG_RTCTDATEW,
	RT5036_REG_STBMODE,
	RT5036_REG_RTCASEC,
	RT5036_REG_RTCAMINUTE,
	RT5036_REG_RTCAHOUR,
	RT5036_REG_RTCAYEAR,
	RT5036_REG_RTCAMONTH,
	RT5036_REG_RTCADATE,
	RT5036_REG_STBCDSEC,
	RT5036_REG_STBCDMINUTE,
	RT5036_REG_STBCDHOUR,
	RT5036_REG_STBCDDATEL,
	RT5036_REG_STBCDDATEH,
	RT5036_REG_RESV4,
	RT5036_REG_STBWACKIRQ,
	RT5036_REG_STBWACKIRQMASK,
	RT5036_REG_RANGE6END = RT5036_REG_STBWACKIRQMASK,
	RT5036_REG_MAX,
};

#define RT5036_DCDCVOUT_SHIFT1	0
#define RT5036_DCDCVOUT_MASK1	0x7F
#define RT5036_DCDCVOUT_SHIFT2	0
#define RT5036_DCDCVOUT_MASK2	0x7F
#define RT5036_DCDCVOUT_SHIFT3	0
#define RT5036_DCDCVOUT_MASK3	0x7F
#define RT5036_DCDCVOUT_SHIFT4	0
#define RT5036_DCDCVOUT_MASK4	0x7F
#define RT5036_DCDCEN_MASK1	0x08
#define RT5036_DCDCEN_MASK2	0x04
#define RT5036_DCDCEN_MASK3	0x02
#define RT5036_DCDCEN_MASK4	0x01
#define RT5036_DCDCMODE_MASK1	0x80
#define RT5036_DCDCMODE_MASK2	0x40
#define RT5036_DCDCMODE_MASK3	0x20
#define RT5036_DCDCMODE_MASK4	0x10
#define RT5036_DCDCRAMP_MASK1	0xC0
#define RT5036_DCDCRAMP_SHIFT1	6
#define RT5036_DCDCRAMP_MASK2	0x30
#define RT5036_DCDCRAMP_SHIFT2	4
#define RT5036_DCDCRAMP_MASK3	0x0C
#define RT5036_DCDCRAMP_SHIFT3	2
#define RT5036_DCDCRAMP_MASK4	0x03
#define RT5036_DCDCRAMP_SHIFT4	0

/*LDO*/
#define RT5036_LDOVOUT_SHIFT1	0
#define RT5036_LDOVOUT_MASK1	0x7F
#define RT5036_LDOVOUT_SHIFT2	0
#define RT5036_LDOVOUT_MASK2	0x7F
#define RT5036_LDOVOUT_SHIFT3	0
#define RT5036_LDOVOUT_MASK3	0x7F
#define RT5036_LDOVOUT_SHIFT4	0
#define RT5036_LDOVOUT_MASK4	0x7F
#define RT5036_LDOEN_MASK1	0x80
#define RT5036_LDOEN_MASK2	0x40
#define RT5036_LDOEN_MASK3	0x20
#define RT5036_LDOEN_MASK4	0x10
#define RT5036_LDOMODE_MASK1	0x80
#define RT5036_LDOMODE_MASK2	0x40
#define RT5036_LDOMODE_MASK3	0x20
#define RT5036_LDOMODE_MASK4	0x10
#define RT5036_LDORAMP_MASK1	0xC0
#define RT5036_LDORAMP_SHIFT1	6
#define RT5036_LDORAMP_MASK2	0x30
#define RT5036_LDORAMP_SHIFT2	4
#define RT5036_LDORAMP_MASK3	0x0C
#define RT5036_LDORAMP_SHIFT3	2
#define RT5036_LDORAMP_MASK4	0x03
#define RT5036_LDORAMP_SHIFT4	0

/*LSW*/
#define RT5036_LSWVOUT_SHIFT1	0
#define RT5036_LSWVOUT_MASK1	0x7F
#define RT5036_LSWVOUT_SHIFT2	0
#define RT5036_LSWVOUT_MASK2	0x7F
#define RT5036_LSWNEN_MASK2	0x02
#define RT5036_LSWNEN_MASK1	0x01
#define RT5036_LSWSEN_MASK2	0x08
#define RT5036_LSWSEN_MASK1	0x04
#define RT5036_LSWNMODE_MASK2	0x80
#define RT5036_LSWNMODE_MASK1	0x40
#define RT5036_LSWSMODE_MASK2	0x08
#define RT5036_LSWSMODE_MASK1	0x04
#define RT5036_LSWNRAMP_MASK2	0xC0
#define RT5036_LSWNRAMP_SHIFT2	6
#define RT5036_LSWNRAMP_MASK1	0x30
#define RT5036_LSWNRAMP_SHIFT1	4
#define RT5036_LSWSRAMP_MASK2	0x0C
#define RT5036_LSWSRAMP_SHIFT2	2
#define RT5036_LSWSRAMP_MASK1	0x03
#define RT5036_LSWSRAMP_SHIFT1	0

struct pmic_rt5036 {
	struct pmic *pmic;
	int node;	/*device tree node*/
	struct fdt_gpio_state pwr_hold;
};

#endif
