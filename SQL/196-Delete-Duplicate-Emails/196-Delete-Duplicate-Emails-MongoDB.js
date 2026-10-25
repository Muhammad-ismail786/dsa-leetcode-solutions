
const duplicates = db.Person.aggregate([
    { $sort: { id: 1 } },
    {
        $group: {
            _id: "$email",
            ids: { $push: "$id" }
        }
    },
    {
        $project: {
            duplicateIds: {
                $slice: ["$ids", 1, { $size: "$ids" }]
            }
        }
    }
]).toArray();

const idsToDelete = duplicates.flatMap(
    item => item.duplicateIds
);

db.Person.deleteMany({
    id: { $in: idsToDelete }
});
