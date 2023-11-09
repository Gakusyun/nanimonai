for YYYY in range(2023,2025):
    for MM in range(1,13):
        for DD in range(1,32):
            if MM in [4,6,9,11]:
                if DD>30:
                    continue
            if MM==2 and YYYY %4==0 and YYYY %100!=0 or YYYY %400==0:
                if DD>29:
                    continue
                elif DD>28:
                    continue
            if MM<10:
                if DD<10:
                    print("[[{}-0{}-0{}]]".format(YYYY,MM,DD))
                else:
                    print("[[{}-0{}-{}]]".format(YYYY,MM,DD))
            else:
                if DD<10:
                    print("[[{}-{}-0{}]]".format(YYYY,MM,DD))
                else:
                    print("[[{}-{}-{}]]".format(YYYY,MM,DD))