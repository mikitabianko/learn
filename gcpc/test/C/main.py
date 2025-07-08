# just for test
import math
from decimal import Decimal, getcontext

getcontext().prec = 30

a = Decimal(input());

result = ((((a / Decimal(math.pi)) ** Decimal(0.5)) + 1) * 2) ** 2
print(f"{result:.10f}") 


# 25779373.7414336279
# 25779373.74143365190567567523737436892329324746211167967177
# 25779373.74143362635
# 25779373.74143362534187110649810488695812890539646900032591