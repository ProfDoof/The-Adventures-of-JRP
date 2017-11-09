#include <iostream>
#include <string>
using namespace std;

class Character;

class Item {
	private:
		string _Name;
		string _Description;
		int _Damage;
		int _Healing;
		
	public:
		Item(string Nam, string Desc, int Dam, int Heal) : _Name(Nam), _Description(Desc), _Damage(Dam), _Healing(Heal)
		~Item();
		
		void Use(Character* ent);
		
		//Getters and Setters
		void Name(string N) { _Name = N; }
		string Name() { return _Name; }
		void Description(string D) { _Description = D; }
		string Description() { return _Description; }
		void Damage(int K) { _Damage = K; }
		int Damage() const { return _Damage; }
		void Healing(int H) { _Healing = H; }
		int Healing() const { return _Healing; }
		class Error {
			private:
				string desc;
			public:
				Error(string description) : desc(description) {}
		};
};

class Curio {
	private:
		int something
};
