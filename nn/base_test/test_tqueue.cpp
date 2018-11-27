#include "queue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<int> p(4));
}

TEST(TQueue, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue<int> p(-4));
}

TEST(TQueue, can_add_in_full_queue)
{
	int i = MaxQueueSize + 1;
	ASSERT_ANY_THROW(TQueue<int> p(i));
}

TEST(TQueue, can_get_next_elem_from_the_queue)
{
	TQueue<int> p(4);
	EXPECT_EQ(p.GetNextIndex(1), 2);
}
TEST(TQueue, can_put_elem)
{
	TQueue<int> p(4);
	ASSERT_NO_THROW(p.Push(2));
}

TEST(TQueue, can_get_elem)
{
	TQueue<int> p(4);
	p.Push(2);
	ASSERT_NO_THROW(p.Pop());
}

TEST(TQueue, can_correcttly_get_elem_from_the_queue)
{
	TQueue<int> p(4);
	p.Push(2);
	EXPECT_EQ(p.Pop(), 2);
}

TEST(TQueue, can_check_queue_is_empty)
{
	TQueue<int> p(4);
	p.Push(1);
	EXPECT_EQ(p.IsEmpty(), 0);
	EXPECT_EQ(p.IsFull(), 0);
}

TEST(TQueue, can_check_queue_is_full)
{
	TQueue<int> p(2);
	p.Push(1);
	p.Push(2);
	EXPECT_EQ(p.IsFull(), 1);
}

TEST(TQueue, can_not_qet_elem_from_empty_queue)
{
	TQueue<int> p(2);
	p.Push(1);
	p.Pop();
	ASSERT_ANY_THROW(p.Pop());
}

TEST(TQueue, can_not_put_elem_in_full_queue)
{
	TQueue<int> p(2);
	p.Push(1);
	p.Push(2);
	ASSERT_ANY_THROW(p.Push(3));
}
TEST(TQueue, can_learn_the_first_element_queue)
{
	TQueue<int> p(2);
	p.Push(4);
	EXPECT_EQ(p.Check(), 4);
}
