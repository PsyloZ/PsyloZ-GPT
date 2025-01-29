// handles custom bullet effects
		// add bulletEffect entry to CfgAmmo entry (inherits from Bullet_Base)
		// the class put in must inherit from BulletEffectBase
		// effect is created on client AND server
class BulletEffectBase: ScriptedEntity
{
    void Play(Object source, Object direct_hit, int component, string surface, vector position, vector normal, vector exit_position, vector enter_velocity, vector exit_velocity, bool water, bool deflected)
    {
    }
}