//
// Created by JavaMan on 2021/11/8.
//

#include "CppRing.h"

Entity::CppRing::CppRing() {

}

Entity::CppRing::~CppRing() {

}


void Entity::CppRing::ring_alloc(Ring *ring, int capacity) {
    ring->capacity = capacity;
    ring->start = 0;
    ring->end = 0;
//    ring->data = (RingEntry *)calloc(capacity, sizeof(RingEntry));
    ring->data = new RingEntry[capacity];
}

void Entity::CppRing::ring_free(Ring *ring) {
//    free(ring->data);
    delete ring->data;
}

int Entity::CppRing::ring_empty(Ring *ring) {
    return ring->start == ring->end;
}

int Entity::CppRing::ring_full(Ring *ring) {
    return ring->start == (ring->end + 1) % ring->capacity;
}

int Entity::CppRing::ring_size(Ring *ring) {
    if (ring->end >= ring->start) {
        return ring->end - ring->start;
    }
    else {
        return ring->capacity - (ring->start - ring->end);
    }
}

void Entity::CppRing::ring_grow(Ring *ring) {
    Ring new_ring;
    RingEntry entry;
    ring_alloc(&new_ring, ring->capacity * 2);
    while (ring_get(ring, &entry)) {
        ring_put(&new_ring, &entry);
    }
//    free(ring->data);
    delete ring->data;
    ring->capacity = new_ring.capacity;
    ring->start = new_ring.start;
    ring->end = new_ring.end;
    ring->data = new_ring.data;
}

void Entity::CppRing::ring_put(Ring *ring, RingEntry *entry) {
    if (ring_full(ring)) {
        ring_grow(ring);
    }
    RingEntry *e = ring->data + ring->end;
    memcpy(e, entry, sizeof(RingEntry));
    ring->end = (ring->end + 1) % ring->capacity;
}

void Entity::CppRing::ring_put_block(Ring *ring, int p, int q, int x, int y, int z, int w) {
    RingEntry entry;
    entry.type = BLOCK;
    entry.p = p;
    entry.q = q;
    entry.x = x;
    entry.y = y;
    entry.z = z;
    entry.w = w;
    ring_put(ring, &entry);
}

void Entity::CppRing::ring_put_light(Ring *ring, int p, int q, int x, int y, int z, int w) {
    RingEntry entry;
    entry.type = LIGHT;
    entry.p = p;
    entry.q = q;
    entry.x = x;
    entry.y = y;
    entry.z = z;
    entry.w = w;
    ring_put(ring, &entry);
}

void Entity::CppRing::ring_put_key(Ring *ring, int p, int q, int key) {
    RingEntry entry;
    entry.type = KEY;
    entry.p = p;
    entry.q = q;
    entry.key = key;
    ring_put(ring, &entry);
}

void Entity::CppRing::ring_put_commit(Ring *ring) {
    RingEntry entry;
    entry.type = COMMIT;
    ring_put(ring, &entry);
}

void Entity::CppRing::ring_put_exit(Ring *ring) {
    RingEntry entry;
    entry.type = EXIT;
    ring_put(ring, &entry);
}

int Entity::CppRing::ring_get(Ring *ring, RingEntry *entry) {
    if (ring_empty(ring)) {
        return 0;
    }
    RingEntry *e = ring->data + ring->start;
    memcpy(entry, e, sizeof(RingEntry));
    ring->start = (ring->start + 1) % ring->capacity;
    return 1;
}
