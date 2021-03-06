//
// Created by koncord on 23.07.16.
//

#include "GUI.hpp"
#include <apps/openmw-mp/Script/ScriptFunctions.hpp>
#include <apps/openmw-mp/Networking.hpp>
#include <components/openmw-mp/NetworkMessages.hpp>

void GUIFunctions::_MessageBox(unsigned short pid, int id, const char *label) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->guiMessageBox.id = id;
    player->guiMessageBox.label = label;
    player->guiMessageBox.type = Player::GUIMessageBox::MessageBox;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->Send(false);
}

void GUIFunctions::CustomMessageBox(unsigned short pid, int id, const char *label, const char *buttons) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->guiMessageBox.id = id;
    player->guiMessageBox.label = label;
    player->guiMessageBox.buttons = buttons;
    player->guiMessageBox.type = Player::GUIMessageBox::CustomMessageBox;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->Send(false);
}

void GUIFunctions::InputDialog(unsigned short pid, int id, const char *label) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->guiMessageBox.id = id;
    player->guiMessageBox.label = label;
    player->guiMessageBox.type = Player::GUIMessageBox::InputDialog;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->Send(false);
}

void GUIFunctions::PasswordDialog(unsigned short pid, int id, const char *label, const char *note) noexcept
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->guiMessageBox.id = id;
    player->guiMessageBox.label = label;
    player->guiMessageBox.note = note;
    player->guiMessageBox.type = Player::GUIMessageBox::PasswordDialog;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->Send(false);
}

void GUIFunctions::ListBox(unsigned short pid, int id, const char *label, const char *items)
{
    Player *player;
    GET_PLAYER(pid, player,);

    player->guiMessageBox.id = id;
    player->guiMessageBox.label = label;
    player->guiMessageBox.data = items;
    player->guiMessageBox.type = Player::GUIMessageBox::ListBox;

    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->setPlayer(player);
    mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_GUI_MESSAGEBOX)->Send(false);
}

void GUIFunctions::SetMapVisibility(unsigned short targetPID, unsigned short affectedPID, unsigned short state) noexcept
{
    LOG_MESSAGE(Log::LOG_WARN, "stub");
}

void GUIFunctions::SetMapVisibilityAll(unsigned short targetPID, unsigned short state) noexcept
{
    LOG_MESSAGE(Log::LOG_WARN, "stub");
}
