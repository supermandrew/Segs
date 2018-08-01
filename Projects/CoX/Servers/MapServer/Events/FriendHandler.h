/*
 * SEGS - Super Entity Game Server
 * http://www.segs.io/
 * Copyright (c) 2006 - 2018 SEGS Team (see AUTHORS.md)
 * This software is licensed under the terms of the 3-clause BSD License. See LICENSE.md for details.
 */

#pragma once
#include "EventProcessor.h"
#include "Servers/MessageBusEndpoint.h"
#include "Servers/InternalEvents.h"
#include <unordered_map>
#include <vector>

class FriendHandler : public EventProcessor
{
    //Key is ID of character who comes online, value is vector of IDs who have added this friend
    static std::unordered_map<int,std::vector<int>> friend_map;
private:
    void on_client_connected(ClientConnectedMessage* msg);
    void on_client_disconnected(ClientDisconnectedMessage* msg);
protected:
    MessageBusEndpoint m_message_bus_endpoint;
public:
    FriendHandler();
    void dispatch(SEGSEvent *ev) override;
};
