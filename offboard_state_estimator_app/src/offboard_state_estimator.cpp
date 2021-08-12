#include "mocap_quadcopterSubscriber.h"
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>

#include "mocap_quadcopterPubSubTypes.h"

namespace subscriber {

void mocap_quadcopterSubscriber::SubListener::on_data_available(
    eprosima::fastdds::dds::DataReader *reader) {
  // Take data
  mocap_quadcopter st;
  eprosima::fastdds::dds::SampleInfo info;

  if (reader->take_next_sample(&st, &info) == ReturnCode_t::RETCODE_OK) {
    if (info.valid_data) {
      // Print your structure data here.
      ++samples;
      std::cout << "\nSample received, count=" << samples << std::endl;
      std::cout << "Index=" << st.index() << std::endl;

      std::cout << "Object Name:" << st.object_name() << std::endl;

      object_name = st.object_name();
      frame_number = st.index();

      position[0] = st.position().at(0);
      position[1] = st.position().at(1);
      position[2] = st.position().at(2);

      orientation[0] = st.orientation_quaternion().at(0);
      orientation[1] = st.orientation_quaternion().at(1);
      orientation[2] = st.orientation_quaternion().at(2);
      orientation[3] = st.orientation_quaternion().at(3);

      latency = st.delay();

      std::cout << "Position      :" << position[0] << '\t' << position[1]
                << '\t' << position[2] << std::endl;

      std::cout << "Orientation:" << orientation[0] << '\t' << orientation[1]
                << '\t' << orientation[2] << '\t' << orientation[3] << std::endl
                << std::endl;
    }
  }
}
} // namespace subscriber

int main() {
  subscriber::mocap_quadcopterSubscriber mysub;
  mysub.init();

  while (1) {

    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Sleep 1 ms
  }

  return 0;
}

// int main() { return subscriber::main(); }