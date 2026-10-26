# 197. Rising Temperature — MongoDB

**# Intuition**

Humein un dinon ki IDs find karni hain jin ka temperature pichlay din se zyada tha. MongoDB mein hum aggregation pipeline se aaj aur pichlay din ka data compare karenge.

**# Approach**

1. `$lookup` se `Weather` collection mein pichlay din ka record search karte hain.
2. `$dateSubtract` se current date mein se ek din minus karte hain.
3. `$expr` aur `$and` se date aur temperature ki conditions check karte hain.
4. `$match` se sirf woh records rakhte hain jin ka pichlay din ka record mil gaya.
5. `$project` se sirf `id` return karte hain aur `_id` ko hide karte hain.

**# Complexity**

- Time complexity: Exact complexity indexes, data size aur MongoDB ke query plan par depend karti hai.
- Space complexity: Exact additional space query plan aur matching records par depend karti hai.

**# Code**

```javascript
db.Weather.aggregate([
  {
    $lookup: {
      from: "Weather",
      let: {
        todayDate: "$recordDate",
        todayTemp: "$temperature"
      },
      pipeline: [
        {
          $match: {
            $expr: {
              $and: [
                {
                  $eq: [
                    "$recordDate",
                    {
                      $dateSubtract: {
                        startDate: "$$todayDate",
                        unit: "day",
                        amount: 1
                      }
                    }
                  ]
                },
                { $lt: ["$temperature", "$$todayTemp"] }
              ]
            }
          }
        }
      ],
      as: "yesterday"
    }
  },
  {
    $match: {
      "yesterday.0": { $exists: true }
    }
  },
  {
    $project: {
      _id: 0,
      id: 1
    }
  }
]);
```
