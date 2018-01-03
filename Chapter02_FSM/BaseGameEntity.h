#pragma once

struct Telegram;
enum Entity_Id { BOB, ELSA };

class BaseGameEntity
{
public:
	BaseGameEntity(int newId)
	{
		SetId(newId);
	}
	virtual ~BaseGameEntity() {}

	virtual void Update() = 0;
	virtual bool HandleMessage(const Telegram& msg) = 0;
	int GetId() const { return id; }

private:
	void SetId(int newId);

private:
	static int		nextValidId;
	int				id;
};

