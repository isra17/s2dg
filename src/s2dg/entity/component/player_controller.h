#ifndef S2DG_PLAYER_CONTROLLER_H
#define S2DG_PLAYER_CONTROLLER_H

#include "../component.h"

namespace s2dg {
	namespace com {
		class PlayerController :
			public Component {
		public:
			static const int CID;
			static const std::string NAME;

			PlayerController(float speed);
			virtual ~PlayerController();

			void update(const sf::Time& elapsed) override;

		private:
			float _speed;
		};
	}
}

#endif
