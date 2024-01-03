class AbstractEvent {
public:
	virtual void display() const = 0;
	/*virtual string description() const {
		return "generic event";
	}*/
	virtual ~AbstractEvent() {}

};


