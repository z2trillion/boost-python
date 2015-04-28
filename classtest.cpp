#include <string>
using namespace std;

class RunningMean{
	public:
		RunningMean();
		void update(int);
		float getMean();
	private:
		int total;
		int count;
};

RunningMean::RunningMean(){
	total = 0;
	count = 0;
};

void RunningMean::update(int x){
	total += x;
	count += 1;
};

float RunningMean::getMean(){
	// ignoring div by 0 here...
	return float(total) / float(count);
};

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(classtest){
	class_<RunningMean>("RunningMean", init<>())
		.def("update", &RunningMean::update)
		.def("getMean", &RunningMean::getMean);
}
