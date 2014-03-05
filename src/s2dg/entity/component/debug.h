#ifndef S2DG_COM_DEBUG_H
#define S2DG_COM_DEBUG_H

#include "../component.h"

#include <string>

namespace s2dg {
	namespace com {
		
		class Debug : public Component {
		public:
			static const int CID;
			static const std::string NAME;

			Debug();
			virtual ~Debug();

			void update() override;
		};
	}
}
#endif
