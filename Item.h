#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>

class Character;

class Item {
	private:
        std::string _Name;
        std::string _Description;
		int _Damage;
		int _Healing;
		int _Defense;
		
	public:
		Item(std::string Nam, std::string Desc, int Dam, int Heal, int Def) : _Name(Nam), _Description(Desc), _Damage(Dam), _Healing(Heal), _Defense(Def) {}
		
		//Getters and Setters
		void Name(std::string N) { _Name = N; }
        std::string Name() { return _Name; }
		void Description(std::string D) { _Description = D; }
        std::string Description() { return _Description; }
		void Damage(int K) { _Damage = K; }
		int Damage() const { return _Damage; }
		void Healing(int H) { _Healing = H; }
		int Healing() const { return _Healing; }
		void Defense(int D) { _Defense = D; }
		int Defense() const { return _Defense; }
		class Error {
			private:
                std::string desc;
			public:
				Error(std::string description) : desc(description) {}
		};
};

class Curio {
	private:
		int something;
};
#endif
