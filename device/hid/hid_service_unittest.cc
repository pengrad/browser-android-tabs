// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "device/hid/hid_service.h"
#include "base/bind.h"
#include "base/run_loop.h"
#include "base/test/scoped_task_environment.h"
#include "device/hid/public/interfaces/hid.mojom.h"
#include "testing/gtest/include/gtest/gtest.h"

namespace device {

namespace {

class HidServiceTest : public ::testing::Test {
 public:
  HidServiceTest()
      : scoped_task_environment_(
            base::test::ScopedTaskEnvironment::MainThreadType::UI) {}

 protected:
  base::test::ScopedTaskEnvironment scoped_task_environment_;
  std::unique_ptr<HidService> service_;
};

void OnGetDevices(const base::Closure& quit_closure,
                  std::vector<device::mojom::HidDeviceInfoPtr> devices) {
  // Since there's no guarantee that any devices are connected at the moment
  // this test doesn't assume anything about the result but it at least verifies
  // that devices can be enumerated without the application crashing.
  quit_closure.Run();
}

}  // namespace

TEST_F(HidServiceTest, GetDevices) {
  service_ = HidService::Create();
  ASSERT_TRUE(service_);

  base::RunLoop loop;
  service_->GetDevices(base::Bind(&OnGetDevices, loop.QuitClosure()));
  loop.Run();
}

}  // namespace device
