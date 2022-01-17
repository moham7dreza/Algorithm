class Greedy:
    def bulldozer(self):
        input_array = input().split(' ')
        n = int(input_array[0])
        a = int(input_array[1])
        b = int(input_array[2])
        h_array = input().split(' ')
        h_array = [int(hi) for hi in h_array]
        max_height = max(h_array)
        costs = []
        height = h_array[0]
        while height <= max_height:
            cost = 0
            tomb_sum = 0
            bulldozer_action = False
            for i in range(n):
                tomb_sum += h_array[i]
                need_sum = (i + 1) * height
                if tomb_sum <= need_sum:
                    cost += (need_sum - tomb_sum) * a
                    tomb_sum = need_sum
                else:
                    bulldozer_action = True
            addition = tomb_sum - need_sum
            columns_left = addition // height
            addition -= columns_left * height
            if addition > 0:
                cost += (height - addition) * a
            if bulldozer_action:
                cost += b
            costs.append(cost)
            height += 1
        print(min(costs))


if __name__ == '__main__':
    algo = Greedy()
    algo.bulldozer()
