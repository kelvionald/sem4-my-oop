#pragma once

class CTVSet
{
public:
	void TurnOff();
	void TurnOn();
	void SelectChannel(int channel);
	int GetChannel() const;
	bool IsTurnedOn() const;

private:
	bool m_isEnabled = false;
	int m_channel = 1;
	const int m_minChannel = 1;
	const int m_maxChannel = 99;
};