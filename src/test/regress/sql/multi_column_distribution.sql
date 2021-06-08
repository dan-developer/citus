CREATE SCHEMA multi_column_distribution;
SET search_path TO multi_column_distribution;
SET citus.shard_count TO 4;
SET citus.shard_replication_factor TO 1;
SET citus.next_shard_id TO 27905500;

create table t(id int, a int);
select create_distributed_table('t', ARRAY['id']);
select * from pg_dist_partition;

create table t2(id int, a int);
select create_distributed_table('t2', ARRAY['id', 'a']);
select * from pg_dist_partition;
SET client_min_messages TO WARNING;
DROP SCHEMA multi_column_distribution CASCADE;
