#pragma once

class BaseGameEntity
{
public:
	BaseGameEntity(int newId)
	{
		SetId(newId);
	}
	virtual ~BaseGameEntity() {}

	virtual void Update() = 0;
	int GetId() const { return id; }

private:
	void SetId(int newId);

private:
	static int		nextValidId;
	int				id;
};

