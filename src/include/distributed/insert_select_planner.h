/*-------------------------------------------------------------------------
 *
 * insert_select_planner.h
 *
 * Declarations for public functions and types related to planning
 * INSERT..SELECT commands.
 *
 * Copyright (c) Citus Data, Inc.
 *
 *-------------------------------------------------------------------------
 */

#ifndef INSERT_SELECT_PLANNER_H
#define INSERT_SELECT_PLANNER_H


#include "postgres.h"

#include "distributed/multi_physical_planner.h"
#include "distributed/distributed_planner.h"
#include "nodes/execnodes.h"
#include "nodes/parsenodes.h"
#include "nodes/plannodes.h"


extern bool InsertSelectIntoCitusTable(Query *query);
extern bool CheckInsertSelectQuery(Query *query);
extern bool InsertSelectIntoLocalTable(Query *query);
extern Query * ReorderInsertSelectTargetLists(Query *originalQuery,
											  RangeTblEntry *insertRte,
											  RangeTblEntry *subqueryRte);
extern void NonPushableInsertSelectExplainScan(CustomScanState *node, List *ancestors,
											   struct ExplainState *es);
extern DistributedPlan * CreateInsertSelectPlan(uint64 planId, Query *originalQuery,
												PlannerRestrictionContext *
												plannerRestrictionContext,
												ParamListInfo boundParams);
extern DistributedPlan * CreateInsertSelectIntoLocalTablePlan(uint64 planId,
															  Query *originalQuery,
															  ParamListInfo
															  boundParams, bool
															  hasUnresolvedParams,
															  PlannerRestrictionContext *
															  plannerRestrictionContext);
extern char * InsertSelectResultIdPrefix(uint64 planId);
extern bool PlanningInsertSelect(void);
extern Query * WrapSubquery(Query *subquery);


#endif /* INSERT_SELECT_PLANNER_H */
