#ifndef DOOR_H_
#define DOOR_H_

class Door
{
private:
	bool open;
public:
	Door();
	void Open();
	void Close();
	bool IsOpen() const;
};

#endif