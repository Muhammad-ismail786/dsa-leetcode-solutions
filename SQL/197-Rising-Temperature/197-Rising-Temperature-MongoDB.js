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
