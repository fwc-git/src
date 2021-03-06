// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/chromeos/policy/remote_commands/user_commands_factory_chromeos.h"

#include "base/logging.h"
#include "chrome/browser/chromeos/policy/remote_commands/user_command_arc_job.h"
#include "components/policy/core/common/remote_commands/remote_command_job.h"
#include "components/policy/proto/device_management_backend.pb.h"

namespace em = enterprise_management;

namespace policy {

UserCommandsFactoryChromeOS::UserCommandsFactoryChromeOS(Profile* profile)
    : profile_(profile) {}

UserCommandsFactoryChromeOS::~UserCommandsFactoryChromeOS() = default;

std::unique_ptr<RemoteCommandJob> UserCommandsFactoryChromeOS::BuildJobForType(
    em::RemoteCommand_Type type) {
  switch (type) {
    case em::RemoteCommand_Type_USER_ARC_COMMAND:
      return std::make_unique<UserCommandArcJob>(profile_);
    default:
      // Other types of commands should be sent to DeviceCommandsFactoryChromeOS
      // instead of here.
      NOTREACHED();
      return nullptr;
  }
}

}  // namespace policy
