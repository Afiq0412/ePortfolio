use ("clinicdb");

// Part B - Appointments Reporting
// Question B1 - Advanced Query and Sorting
db.appointments.find({status : "COMPLETED", fee: {$gte: 100, $lte: 300}}, 
    {appointmentId: 1, patientName: 1, department: 1, fee: 1}).sort({department: 1, fee: -1})

// Question B2 - Aggregation Summary
db.appointments.aggregate([
    {$group: { _id: "$department", totalAppointments: {$sum: 1}, totalFees: {$sum: "$fee"}}},
    {$sort:  {totalFees: -1}}
])

// Part C - Clinic Security Monitoring
// Question C1 - Active Staff Sessions
db.loginSessions.find({status: "ACTIVE"},
    {staffName: 1, role: 1, ipAddress: 1, loginTime: 1}).sort({loginTime: -1})

// Question C2 - Distinct and Count
// a.
db.loginSessions.distinct("ipAddress", {status: "ACTIVE"})

// b.
db.loginSessions.aggregate([
    {$match: {status: "ACTIVE"}},
    {$group: {_id: "$staffName", count: {$sum: 1}}}
])

// Part D - Indexing and Data Maintenance
// Question D1 - Compound Index
db.appointments.createIndex({department: 1, status: 1})

db.appointments.find({department: "Psychiatry", status: "COMPLETED"})

// Question D2 - Update & Delete Operations
// a.
db.appointments.updateMany(
    {status: "CANCELLED"},
    {$set: {status: "ARCHIVED"}}
)

db.appointments.find({})

// b.
db.loginSessions.deleteMany({status: "INACTIVE"})