#ifndef ANT_H
#define ANT_H


class Ant{
	private:
		int id;
		int x;
		int y;
		int xp;
	public:
		//Ant(){id=-1;};
		Ant(int);
		Ant(Ant*);		//copy Constructor
		int move(int);		//moves within grid;
		int fight();

		 int getID(){
			return id;
			}
		 int getX(){
			return x;
			}
		 int getY(){
			return y;
			}

			int getXp(){
				return xp;
			}

};

#endif
