#include <vector>
#include <boost/foreach.hpp>

using namespace std;

class Environment {
	public:
		//vector<object_type*> ships;	
		Environment ();
		int update();
		int addObject(/*Object_Type * */);
		int removeObject(/*Object_Type * */);
		
};
