#include "CTVSet.h"

void CTVSet::TurnOff()
{
	m_isEnabled = false;
}

void CTVSet::TurnOn()
{
	m_isEnabled = true;
}

void CTVSet::SelectChannel(int channel)
{
	if (!m_isEnabled)
	{
		return;
	}
	if (m_minChannel <= channel && channel <= m_maxChannel)
	{
		m_channel = channel;
	}
}

int CTVSet::GetChannel() const
{
	if (m_isEnabled)
	{
		return m_channel;
	}
	return 0;
}

bool CTVSet::IsTurnedOn() const
{
	return m_isEnabled;
}
