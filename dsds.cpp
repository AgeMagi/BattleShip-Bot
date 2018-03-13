			int ujungkanan = shotLocation.x;
			int ujungkiri = shotLocation.x;
			int panjang = 0;

			while(map[ujungkanan][shotLocation.y].damaged) {
				ujungkanan++;
				if (ujungkanan == size) {
					break;
				}
			}
			while(map[ujungkiri][shotLocation.y].damaged) {
				ujungkiri--;
				if (ujungkiri == -1) {
					break;
				}
			}

			if (shotLocation.y > 0) {
				if (!map[ujungkanan][shotLocation.y-1].damaged && !map[ujungkanan][shotLocation.y-1].missed) {
					shotLocation.x = ujungkanan;
					shotLocation.y--;
					return shotLocation;
				}
			}

			if (shotLocation.y < size) {
				if (!map[ujungkanan][shotLocation.y+1].damaged && !map[ujungkanan][shotLocation.y+1].missed) {
					shotLocation.x = ujungkanan;
					shotLocation.y++;
					return shotLocation;
				}
			}

			if (shotLocation.y > 0) {
				if (!map[ujungkiri][shotLocation.y-1].damaged && !map[ujungkiri][shotLocation.y-1].missed) {
					shotLocation.x = ujungkiri;
					shotLocation.y--;
					return shotLocation;
				}
			}

			if (shotLocation.y < size) {
				if (!map[ujungkanan][shotLocation.y+1].damaged && !map[ujungkiri][shotLocation.y+1].missed) {
					shotLocation.x = ujungkiri;
					shotLocation.y++;
					return shotLocation;
				}
			}


			if (ujungkanan - ujungkiri + 1 > 6) {
				for(int i = 1; i <= 4; i++) {
					if (ujungkiri + i <= ujungkanan) {
						if (!map[ujungkiri + i][shotLocation.y + 1].damaged && !map[ujungkiri + i][shotLocation.y+1].missed) {
							shotLocation.x = ujungkiri + i;
							shotLocation.y++;
							return shotLocation;
						}
						if (!map[ujungkiri + i][shotLocation.y - 1].damaged && !map[ujungkiri + i][shotLocation.y-1].missed) {
							shotLocation.x = ujungkiri + i;
							shotLocation.y--;
							return shotLocation;
						}
					}
				}

				for(int i = 1; i <= 4; i++) {
					if (ujungkanan - i >= ujungkiri) {
						if (!map[ujungkanan - i][shotLocation.y + 1].damaged && !map[ujungkanan - i][shotLocation.y+1].missed) {
							shotLocation.x = ujungkanan + i;
							shotLocation.y++;
							return shotLocation;
						}
						if (!map[ujungkanan - i][shotLocation.y - 1].damaged && !map[ujungkanan - i][shotLocation.y-1].missed) {
							shotLocation.x = ujungkanan - i;
							shotLocation.y--;
							return shotLocation;
						}
					}
				}