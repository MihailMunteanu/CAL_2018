
#include "m_qei.h"

T_F16 QEI_s16getElapsed(void)
{
	T_S16 s16counted = 0;
	T_F16 f16cmDriven = 0;
	s16counted = -(QEI_u16getCount() - middleValue);
	QEI_vResetCount();
	f16cmDriven = (T_F16)s16counted / 100;
	return f16cmDriven;
}
	