#ifdef REARMED_SERVER
class BulletEffect_RPG7: BulletEffectBase
{
    override void Play(Object source, Object direct_hit, int component, string surface, vector position, vector normal, vector exit_position, vector enter_velocity, vector exit_velocity, bool water, bool deflected)
    {
        // check for deflections and penetration
        if (!g_Game.IsServer() || deflected || exit_velocity.Length() > 0) {
            return;
        }

        Explosive_RPG7 explosive_rpg7 = Explosive_RPG7.Cast(g_Game.CreateObjectEx("Explosive_RPG7", GetPosition(), ECE_NONE));
        if (explosive_rpg7) {
            explosive_rpg7.DoExplosion(EntityAI.Cast(source));
            Delete();
        }
    } 
}
#endif