# 197. Rising Temperature — Pandas

**# Intuition**

Humein un dinon ki IDs find karni hain jin ka temperature pichlay din se zyada tha. Pandas mein hum `merge()` use karke dono dinon ka data match kar sakte hain.

**# Approach**

1. `weather.copy()` se data ki do copies banate hain.
2. `pd.to_datetime()` dates ko date format mein convert karta hai.
3. `pd.Timedelta(days=1)` date mein ek din add karta hai.
4. `merge()` dono data copies ko date ke through match karta hai.
5. Temperature compare karke sirf un dinon ki IDs return karte hain jin ka temperature barha tha.

**# Complexity**

- Time complexity: \(O(n^2)\) worst case — merge ke data size aur implementation par depend karti hai.
- Space complexity: \(O(n)\) additional data copies aur merged result ke liye; worst case mein merge result bara ho sakta hai.

**# Code**

```python
import pandas as pd

def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
    today = weather.copy()
    yesterday = weather.copy()

    today["recordDate"] = pd.to_datetime(today["recordDate"])
    yesterday["recordDate"] = pd.to_datetime(yesterday["recordDate"])

    yesterday["recordDate"] = yesterday["recordDate"] + pd.Timedelta(days=1)

    merged = today.merge(
        yesterday,
        on="recordDate",
        suffixes=("", "_yesterday")
    )

    result = merged[
        merged["temperature"] > merged["temperature_yesterday"]
    ]

    return result[["id"]]
```
