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

			void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		private:
			std::unique_ptr<sf::Shape> _drawable;
		};
	}
}

#endif
