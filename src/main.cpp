#include <iostream>
#include <memory>
#include <string>


class parent;

class child {
public:
	std::weak_ptr<parent> parent_;
	std::string name_;
};


class parent : public std::enable_shared_from_this<parent> {
public:
	std::shared_ptr<child> child_;

	static std::shared_ptr<parent>
	create()
	{
		return std::shared_ptr<parent>(new parent());
	}

	void
	set_child(const child& _child)
	{
		this->child_ = std::make_shared<child>(_child);
		this->child_->parent_ = this->shared_from_this();
	}

private:
	// prevent from creating.
	parent() { }
};


int
main(void)
{
	std::shared_ptr<parent> p = parent::create();

	child c;
	c.name_ = "child1";

	p->set_child(c);

	std::shared_ptr<parent> sh_parent = p->child_->parent_.lock();
	if (sh_parent) {
		std::cout << "Child name: " << sh_parent->child_->name_ << '\n';
	}
	else {
		std::cout << "'" << c.name_
			<< "' parent is already destroyed." << '\n';
	}

	return 0;
}
