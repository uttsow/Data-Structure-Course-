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
		void move();
		Ant * fight(Ant*);

		 int getID(){
			return id;
			}
		 int getX(){
			return x;
			}
		 int getY(){
			return y;
			}



};

#endif
