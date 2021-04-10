class ItemToPurchase:
    def __init__(self, item_name="none", item_price=0.0, item_quantity=0, item_description='none'):
        self.item_name = item_name
        self.item_price = item_price
        self.item_quantity = item_quantity
        self.item_description = item_description

    def print_item_cost(self):
        print('{} {} @ ${:.0f} = ${:.0f}'.format
              (self.item_name, self.item_quantity, self.item_price, self.item_quantity*self.item_price))

    def print_item_description(self):
        print('{}: {}'.format(self.item_name, self.item_description))


class ShoppingCart:
    def __init__(self, customer_name='none', current_date='January 1, 2016'):
        self.customer_name = customer_name
        self.current_date = current_date
        self.cart_items = []

    def add_item(self, item=ItemToPurchase()):
        self.cart_items.append(item)

    def remove_item(self, item_name=''):
        count = 0
        for pos, item in enumerate(self.cart_items):
            if item_name == item.item_name:
                del self.cart_items[pos]
                count += 1
        if count == 0:
            print('Item not found in cart. Nothing removed.')

    def modify_item(self, new_quantity, check_item=''):
        count = 0
        for pos, item in enumerate(self.cart_items):
            if check_item == item.item_name:
                self.cart_items[pos].item_quantity = new_quantity
                count += 1
        if count == 0:
            print('Item not found in cart. Nothing modified.')

    def get_num_items_in_cart(self):
        cart_items_quantity = 0
        if len(self.cart_items) == 0:
            cart_items_quantity = 0
        elif len(self.cart_items) > 0:
            for item in self.cart_items:
                cart_items_quantity += item.item_quantity
        return cart_items_quantity

    def get_cost_of_cart(self):
        cart_items_cost = 0
        if len(self.cart_items) == 0:
            cart_items_cost = 0
        elif len(self.cart_items) > 0:
            for item in self.cart_items:
                cart_items_cost += item.item_quantity*item.item_price
        return cart_items_cost

    def print_total(self):
        print("John Doe's Shopping Cart - {}".format(self.current_date))
        print('Number of Items: {}'.format(self.get_num_items_in_cart()))
        print('')
        if len(self.cart_items) == 0:
            print('SHOPPING CART IS EMPTY')
        else:
            for item in self.cart_items:
                item.print_item_cost()
        print()
        print('Total: ${:.0f}'.format(self.get_cost_of_cart()))

    def print_descriptions(self):
        print("John Doe's Shopping Cart - {}".format(self.current_date))
        print()
        print("Item Descriptions")
        for item in self.cart_items:
            item.print_item_description()


if __name__ == "__main__":

    name = input("Enter customer's name:\n")
    date = input("Enter today's date:\n")
    print()
    print('Customer name: {}'.format(name))
    print("Today's date: {}".format(date))
    shopping_cart = ShoppingCart(name, date)
    print()

    def print_menu(shop=ShoppingCart()):
        while True:
            print('MENU')
            print('a - Add item to cart')
            print('r - Remove item from cart')
            print('c - Change item quantity')
            print("i - Output items' descriptions")
            print('o - Output shopping cart')
            print('q - Quit')
            print()

            while True:
                user_choice = input('Choose an option:\n')
                if user_choice == 'a' or user_choice == 'r' or user_choice == 'c':
                    break
                if user_choice == 'i' or user_choice == 'o' or user_choice == 'q':
                    break

            if user_choice == 'q':
                break

            elif user_choice == 'a':
                print('ADD ITEM TO CART')

                new_item_name = input('Enter the item name:\n')
                new_item_desc = input('Enter the item description:\n')
                new_item_price = float(input('Enter the item price:\n'))
                new_item_quantity = int(input('Enter the item quantity:\n'))
                new_item = ItemToPurchase(new_item_name, new_item_price, new_item_quantity, new_item_desc)
                shop.add_item(new_item)

            elif user_choice == 'r':
                print('REMOVE ITEM FROM CART')
                remove_item_name = input('Enter name of item to remove:\n')
                shop.remove_item(remove_item_name)

            elif user_choice == 'c':
                print('CHANGE ITEM QUANTITY')
                change_qty_item_name = input('Enter the item name:\n')
                new_qty = int(input('Enter the new quantity:\n'))
                shop.modify_item(new_qty, change_qty_item_name)
            elif user_choice == 'i':
                print("OUTPUT ITEMS' DESCRIPTIONS")
                shop.print_descriptions()
            elif user_choice == 'o':
                print('OUTPUT SHOPPING CART')
                shop.print_total()
            print()

    print_menu(shopping_cart)
