#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element 
{
  T isi;
  int pri;
  Element<T> *next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue 
{
  ElementPtr<T> head;
  ElementPtr<T> tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() 
{
  Queue<T> q;
  q.head = nullptr;
  q.tail = nullptr;
  return q;
}

/**
 * @brief memasukan data sesuai pri elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param pri  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int pri) 
{
    ElementPtr<T> newElement = new Element<T>;
  newElement->isi = value;
  newElement->pri = pri;
  newElement->next = nullptr;

  ElementPtr<T> pRev = nullptr;
  if (q.head == nullptr && q.tail == nullptr) 
  {
    q.head = newElement;
    q.tail = newElement;
  } 
  else 
  {
    ElementPtr<T> pHelp = q.head;
    while (newElement->pri <= pHelp->pri) 
    {
      if (pHelp->next == nullptr)
        break;
      pRev = pHelp;
      pHelp = pHelp->next;
    }

    if (pHelp == q.head && newElement->pri > pHelp->pri) 
    {
      newElement->next = pHelp;
      q.head = newElement;
    } 
    else if (pHelp == q.tail && newElement->pri < pHelp->pri) 
    {
      pHelp->next = newElement;
      q.tail = newElement;
    } 
    else 
    {
      pRev->next = newElement;
      newElement->next = pHelp;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) 
{
  return q.head->isi;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) 
{
  ElementPtr<T> del;
  if(q.head== nullptr && q.tail == nullptr)
  {
    del = nullptr;
  }
  else if(q.head->next == nullptr)
  {
    del = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  }
  else
  {
    del = q.head;
    q.head = q.head->next;
    del->next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
