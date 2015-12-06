from sys import stdin

# maintain calorie information for each food item
items = []
# presents calories per gram of
# fat, protein, sugar, starch, alcohol respectively
calories_per_gram = [9, 4, 4, 4, 7]

for line in stdin.readlines():
    if line.strip() != '-':
        # this is a line describing food items for a test case
        items += [line.split()]
    elif items:
        # we've reached the end of a test case (a line containing only '-')
        # and there are items to process, i.e., this is not the end of input
        total_cal = total_fat_cal = 0
        for item in items:
            item_cal = 0
            percent = 0

            for i in range(5):
                # for each item, calculate the calories from each nutrient
                if item[i][-1] == 'g':
                    item_cal += int(item[i][:-1]) * calories_per_gram[i]
                elif item[i][-1] == 'C':
                    item_cal += int(item[i][:-1])
                elif item[i][-1] == '%':
                    # track the percentages listed
                    percent += int(item[i][:-1])

            # so whatever wasn't given in percentages makes up the
            # (100 - percent)% of the food item
            # so let's calculate the total calories in the item
            item_cal = item_cal * 100.0 / (100 - percent)
            # and increase the total calorie count
            total_cal += item_cal

            # update the total amount of fat calories in the diet
            # with the amount of fat calories from this item
            if item[0][-1] == 'g':
                total_fat_cal += int(item[0][:-1]) * calories_per_gram[0]
            elif item[0][-1] == 'C':
                total_fat_cal += int(item[0][:-1])
            elif item[0][-1] == '%':
                total_fat_cal += int(item[0][:-1]) * item_cal / 100.0

        print('{:.0f}%'.format(round(100 * total_fat_cal/total_cal)))

        items = []
        continue
