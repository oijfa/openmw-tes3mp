#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketPlayerFaction.hpp"

using namespace std;
using namespace mwmp;

PacketPlayerFaction::PacketPlayerFaction(RakNet::RakPeerInterface *peer) : PlayerPacket(peer)
{
    packetID = ID_PLAYER_FACTION;
}

void PacketPlayerFaction::Packet(RakNet::BitStream *bs, bool send)
{
    PlayerPacket::Packet(bs, send);

    if (!send)
        player->factionChanges.factions.clear();
    else
        player->factionChanges.count = (unsigned int)(player->factionChanges.factions.size());

    RW(player->factionChanges.count, send);

    for (unsigned int i = 0; i < player->factionChanges.count; i++)
    {
        Faction faction;

        if (send)
            faction = player->factionChanges.factions.at(i);

        RW(faction.factionId, send);
        RW(faction.rank, send);
        RW(faction.isExpelled, send);

        if (!send)
            player->factionChanges.factions.push_back(faction);
    }
}
