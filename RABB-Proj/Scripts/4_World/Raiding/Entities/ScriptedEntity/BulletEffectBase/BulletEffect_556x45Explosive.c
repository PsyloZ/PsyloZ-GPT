class BulletEffect_556x45Explosive: BulletEffectBase
{
    override void Play(Object source, Object direct_hit, int component, string surface, vector position, vector normal, vector exit_position, vector enter_velocity, vector exit_velocity, bool water, bool deflected)
    {
        // check for deflections and penetration
        if (!g_Game.IsServer() || deflected || exit_velocity.Length() > 0) {
            return;
        }

        Explosive_556x45 explosive = Explosive_556x45.Cast(g_Game.CreateObject("Explosive_556x45", position));
        if (explosive) {
            explosive.DoExplosion(EntityAI.Cast(source));
        }
    }
}