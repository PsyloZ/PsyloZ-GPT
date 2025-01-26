modded class EffectSound
{
	void SetVolume(float volume)
	{
		if (m_SoundWaveObject) {
			m_SoundWaveObject.SetVolume(volume);
		}
	}
	
	AbstractWave GetSoundObject()
	{
		return m_SoundWaveObject;
	}
}