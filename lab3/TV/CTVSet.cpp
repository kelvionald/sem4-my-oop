#include "CTVSet.h"
#include <utility>

void CTVSet::TurnOff()
{
	m_isEnabled = false;
}

void CTVSet::TurnOn()
{
	m_isEnabled = true;
}

bool CTVSet::IsAllowRange(int channel)
{
	return m_minChannel <= channel && channel <= m_maxChannel;
}

bool CTVSet::SelectChannel(int channel)
{
	if (!m_isEnabled)
	{
		return false;
	}
	if (IsAllowRange(channel))
	{
		m_previousChannel = m_channel;
		m_channel = channel;
		return true;
	}
	return false;
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

void CTVSet::SelectPreviousChannel()
{
	if (!m_isEnabled || m_previousChannel == 0)
	{
		return;
	}
	std::swap(m_channel, m_previousChannel);
}
