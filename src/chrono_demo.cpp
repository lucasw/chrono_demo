

#include <chrono/physics/ChSystemNSC.h>

using chrono::ChBody;
using chrono::ChVector;

int main(int argc, char* argv[])
{
  chrono::ChSystemNSC ch;

  const double gravity = -9.81;
  ch.Set_G_acc(ChVector<>(0.0, 0.0, gravity));

  auto plane = chrono_types::make_shared<ChBody>();
  plane->SetName("plane");
  plane->SetPos(ChVector<>(0.0, 0.0, -1.0));
  plane->SetBodyFixed(true);
  ch.AddBody(plane);

  auto body = chrono_types::make_shared<ChBody>();
  body->SetName("body");
  body->SetBodyFixed(false);
  body->SetMass(1.0);
  body->SetPos(ChVector<>(0.0, 0.0, 4.0));
  ch.AddBody(body);

  const double time_step = 0.001;
  for (size_t i = 0; i < 1000; ++i) {
    ch.DoStepDynamics(time_step);

    if (i % 10 == 0) {
      std::stringstream ss;
      const auto pos = body->GetPos();
      const double cur_time = i * time_step;
      std::cout << "[" << cur_time << "] " << pos << "\n";
    }
  }

  // TODO(lucasw) how to shut down the system without getting a segfault?
  ch.RemoveBody(body);
  ch.RemoveBody(plane);

  return 0;
}
