class Room{
	private:
<<<<<<< HEAD
		Character* Adventurer;
		Enemy* Monster;//
		Curio* Puzzle;//
		bool Visited;//
		string Name;//
		string Desc;//
		list<Item> LooseItems;//
		int Damage;//
	public:
		Room();
		Room(int MonsterType, string RoomName, string RoomDesc, int dam);

		bool visit() const;
		void visit(bool input);

		string roomname() const;
		void roomname(string input);

		string description() const;
		void description(string desc);

		void AddToFloor(Item ttt);
		Item TakeFrom();

		int Trap() const;
		void Trap(int input);

		Curio* LookAtCurio() const;
		void ChangeCurio(Curio* input);

		Enemy* CurrentEnemy() const;
		void ChangeEnemy(Enemy* input);


};
=======
		Item* ItemInRoom;
		Character* Adventurer;
		Enemy* Monster;
		Curio* Puzzle;
	public:
		
}
>>>>>>> 9e60df95fb3c2dbac6548d9ab23a2e8a823cd308
