/*
 *  Copyright (C) 2025 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "DatabaseOperations.h"

#include "DatabaseManager.h"
#include "ServiceBroker.h"
#include "TextureDatabase.h"
#include "addons/AddonDatabase.h"
#include "music/MusicDatabase.h"
#include "pvr/PVRDatabase.h"
#include "pvr/epg/EpgDatabase.h"
#include "utils/Variant.h"
#include "video/VideoDatabase.h"
#include "view/ViewDatabase.h"

using namespace JSONRPC;
using namespace ADDON;
using namespace PVR;


JSONRPC_STATUS CDatabaseOperations::GetDatabaseName(const std::string &method, ITransportLayer *transport, IClient *client, const CVariant &parameterObject, CVariant &result)
{
  std::string type = parameterObject["type"].asString();

  if (type == "addon")
  {
    result = CServiceBroker::GetDatabaseManager().GetFullDatabaseName(CAddonDatabase::GetDefaultBaseDBName());
  }
  else if (type == "epg")
  {
    result = CServiceBroker::GetDatabaseManager().GetFullDatabaseName(CPVREpgDatabase::GetDefaultBaseDBName());
  }
  else if (type == "music")
  {
    result = CServiceBroker::GetDatabaseManager().GetFullDatabaseName(CMusicDatabase::GetDefaultBaseDBName());
  }
  else if (type == "pvr")
  {
    result = CServiceBroker::GetDatabaseManager().GetFullDatabaseName(CPVRDatabase::GetDefaultBaseDBName());
  }
  else if (type == "texture")
  {
    result = CServiceBroker::GetDatabaseManager().GetFullDatabaseName(CTextureDatabase::GetDefaultBaseDBName());
  }
  else if (type == "video")
  {
    result = CServiceBroker::GetDatabaseManager().GetFullDatabaseName(CVideoDatabase::GetDefaultBaseDBName());
  }
  else if (type == "viewmode")
  {
    result = CServiceBroker::GetDatabaseManager().GetFullDatabaseName(CViewDatabase::GetDefaultBaseDBName());
  }

  return OK;
}
